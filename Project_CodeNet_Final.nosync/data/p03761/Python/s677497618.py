from collections import Counter

n = int(input())
S = [input() for i in range(n)]

s0 = Counter(S[0])

for i in S:
    for j in list(s0):
        if j in i:
            s0[j] = min(s0[j], i.count(j))
        else:
            del s0[j]

s0 = sorted(s0.items())
ans = ''
for i in s0:
    ans += i[0] * i[1]

print(ans)
