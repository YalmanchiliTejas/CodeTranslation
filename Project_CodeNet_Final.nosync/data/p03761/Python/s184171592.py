n = int(input())
S = [input() for _ in range(n)]

d = {chr(i): 50 for i in range(97, 97+26)}
for s in S:
    dcur = {chr(i): 0 for i in range(97, 97+26)}
    for si in s:
        dcur[si] += 1
    for k in d:
        d[k] = min(d[k], dcur[k])

ks = list(d.keys())
ks.sort()

ans = []

for k in ks:
    ans.extend([k] * d[k])

print(''.join(ans))
