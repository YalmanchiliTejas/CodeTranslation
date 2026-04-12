from collections import Counter

n = int(input())
s = [input() for i in range(n)]

c = Counter(s[0])
for i in range(1, n):
    c &= Counter(s[i])

ans = ""
for k, v in sorted(c.items()):
    ans += k * v

print(ans)