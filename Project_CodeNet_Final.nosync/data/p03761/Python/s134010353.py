import collections
n = int(input())
s = [input() for i in range(n)]

ans = [100] * 26
for i in range(26):
    for j in range(n):
        sub = 97 + i
        ans[i] = min(ans[i], s[j].count(chr(sub)))

for i in range(26):
    for j in range(ans[i]):
        print(chr(97 + i), end="")
