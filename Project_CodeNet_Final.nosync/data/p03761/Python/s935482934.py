from collections import Counter
S = [Counter(input()) for _ in range(int(input()))]
ans = ""
for i in range(26):
    c = chr(i + ord('a'))
    ans += c * min(s[c] if c in s else 0 for s in S)
print(ans)