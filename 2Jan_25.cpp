class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    bool checkWord(string s) {
        return isVowel(s[0]) && isVowel(s[s.size() - 1]);
    }

    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> v;
        vector<int> ans;
        int sum = 0;

        for (auto word : words) {
            if (checkWord(word)) {
                sum++;
            }
            v.push_back(sum);
        }

        for (auto a : queries) {
            if (a[0] == 0) {
                ans.push_back(v[a[1]]);
            } else {
                ans.push_back(v[a[1]] - v[a[0] - 1]);
            }
        }

        return ans;
    }
};