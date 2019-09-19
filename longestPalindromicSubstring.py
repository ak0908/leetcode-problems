class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = []
        for i in range(len(s)):
            for j in range(i, len(s)):
                if s[i:j+1][::-1] == s[i:j+1]:
                    res.append(s[i:j+1])
        
        if len(res) == 0: return ""
        return max(res, key=lambda x: len(x))