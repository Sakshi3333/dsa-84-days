// LeetCode 217 - Contains Duplicate
// Pattern: hash set ("wedding guard with a register")

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Accepted: one pass + hash set. Time O(n), space O(n).
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;                     // empty register
        for (int i = 0; i < (int)nums.size(); i++) {
            if (seen.count(nums[i])) return true;    // already in the register: duplicate
            seen.insert(nums[i]);                    // otherwise, write it in
        }
        return false;                                // only after checking everyone
    }

    // Other way: sort, then equal numbers sit next to each other.
    // Time O(n log n), almost no extra space, but it changes the input.
    bool containsDuplicateSorted(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < (int)nums.size(); i++)   // start at 1 so nums[i-1] is always valid
            if (nums[i] == nums[i - 1]) return true;
        return false;
    }

    // Attempt 2 (fixed): compare every pair. Correct, but O(n^2): Time Limit Exceeded.
    bool containsDuplicateBrute(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++)
            for (int j = i + 1; j < (int)nums.size(); j++)
                if (nums[i] == nums[j]) return true; // compare the numbers, not i == j
        return false;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 3, 1}, b = {1, 2, 3, 4};
    vector<int> a2 = a, b2 = b;
    cout << boolalpha
         << s.containsDuplicate(a) << " " << s.containsDuplicate(b) << "\n"              // true false
         << s.containsDuplicateSorted(a2) << " " << s.containsDuplicateSorted(b2) << "\n" // true false
         << s.containsDuplicateBrute(a) << " " << s.containsDuplicateBrute(b) << "\n";    // true false
}
