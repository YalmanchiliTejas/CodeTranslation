n = int(input())
s = [input() for _ in range(n)]

from collections import Counter
tot = Counter(s[0])
for i in range(1, n):
    c = Counter(s[i])

    for k in tot.keys():
        tot[k] = min(tot[k], c[k])

ans = ''
for k in tot.keys():
    ans += k * tot[k]
print(''.join(sorted(ans)))
