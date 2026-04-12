n = int(input())
S = [input() for x in range(n)]

D = {}
for i in list("abcdefghijklmnopqrstuvwxyz"):
    D[i] = 50

for s in S:
    d = {}
    for i in list("abcdefghijklmnopqrstuvwxyz"):
        d[i] = 0
    for ss in list(s):
        d[ss] += 1
    for i in list("abcdefghijklmnopqrstuvwxyz"):
        D[i] = min(d[i],D[i])

D = sorted(D.items(),key=lambda x:x[0])
print(''.join(map(lambda x:x[0]*x[1],D)))