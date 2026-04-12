from collections import defaultdict

n = int(input())
S = [input() for i in range(n)]

a = [2500] * 26

for s in S:
    c = defaultdict(int)
    for i in range(len(s)):
        c[s[i]] += 1
    for i in range(26):
        a[i] = min(a[i], c[chr(97 + i)])

ans = ''
for i in range(26):
    ans += chr(97 + i) * a[i]
print(ans)
