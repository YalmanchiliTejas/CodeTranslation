N = int(input())
S = []
for i in range(N):
    S.append(input())

D = {}
for s in S[0]:
    if s not in D:
        D[s] = 0
    D[s] += 1

for s in S:
    d = {}
    for i in s:
        if i not in d.keys():
            d[i] = 0
        d[i] += 1

    for k,v in d.items():
        if k not in D.keys():
            continue
        if D[k] > d[k]:
            D[k] = d[k]

    for k in D.keys():
        if k not in d.keys():
            D[k] = 0

keys =sorted(D)
ans = ""
for k in keys:
    if D[k] != 0:
        for v in range(D[k]):
            ans += k
print(ans)
