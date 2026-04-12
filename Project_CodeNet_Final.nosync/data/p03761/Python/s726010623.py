from collections import Counter

n = int(input())
ctr= [Counter(input()) for _ in range(n)]

c = ctr[0]
for i in range(1, n):
    for k, v in c.items():
        c[k] = min(ctr[i][k], c[k])

ans = ''
for k, v in sorted(c.items()):
    ans += k * v

print(ans)