from collections import Counter

N = int(input())
S = [input() for _ in range(N)]

c = Counter(S[0])
for s in S[1:]:
    c &= Counter(s)

ans = ''
for k, v in sorted(c.items()):
    ans += k * v
print(ans)