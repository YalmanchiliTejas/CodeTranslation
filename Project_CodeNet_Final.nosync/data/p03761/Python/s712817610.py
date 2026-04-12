import collections

n = int(input())
c = collections.Counter(input())
for _ in range(n-1):
    sc = set(c.keys())
    nc = collections.Counter(input())
    snc = set(nc.keys())
    inter = sc & snc
    r = dict()
    for i in inter:
        r[i] = min(c[i], nc[i])
    c = r
if len(c) == 0:
    print('')
else:
    l = []
    for i in sorted(c.items(), key=lambda x: x[0]):
        l.append(i[0]*i[1])
    print(''.join(l))