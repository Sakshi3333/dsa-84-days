// LeetCode 242 - Valid Anagram
// Pattern: counting ("two notebooks" / "one bag of letter tiles")

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Accepted (my solution): two maps, then compare. Time O(n), space O(1) (at most 26 letters each).
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;   // different lengths can't match
        unordered_map<char, int> countS, countT;  // two notebooks: letter -> how many times
        for (char c : s) countS[c]++;             // count every letter of s
        for (char c : t) countT[c]++;             // count every letter of t
        return countS == countT;                  // same notebooks? anagram
    }

    // Upgrade: one array of 26 boxes. +1 for s, -1 for t, every box must end at 0.
    bool isAnagramArray(string s, string t) {
        if (s.size() != t.size()) return false;
        int count[26] = {0};
        for (int i = 0; i < (int)s.size(); i++) {
            count[s[i] - 'a']++;   // tile into the bag
            count[t[i] - 'a']--;   // tile out of the bag
        }
        for (int x : count) if (x != 0) return false;
        return true;
    }

    // Other way: sort both words and compare. Time O(n log n).
    bool isAnagramSorted(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main() {
    Solution sol;
    cout << boolalpha
         << sol.isAnagram("anagram", "nagaram") << " " << sol.isAnagram("rat", "car") << "\n"             // true false
         << sol.isAnagramArray("anagram", "nagaram") << " " << sol.isAnagramArray("rat", "car") << "\n"   // true false
         << sol.isAnagramSorted("anagram", "nagaram") << " " << sol.isAnagramSorted("rat", "car") << "\n"; // true false
}
