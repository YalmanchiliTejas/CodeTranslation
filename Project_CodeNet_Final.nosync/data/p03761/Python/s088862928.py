from collections import Counter

n = int(input())
S = [input() for _ in range(n)]

a = Counter(S[0])
for s in S:
    a &= Counter(s)

ans = ''
for k, v in sorted(a.items()):
    ans += k * v
print(ans)
