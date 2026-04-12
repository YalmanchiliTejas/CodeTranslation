from collections import Counter

n = int(input())
S = [input() for _ in range(n)]

res = Counter(S[0])

for s in S[1:]:
    c = Counter(s)
    res = res & c

ans = ""
for key in res.keys():
    ans += key * res[key]

print("".join(sorted(ans)))
