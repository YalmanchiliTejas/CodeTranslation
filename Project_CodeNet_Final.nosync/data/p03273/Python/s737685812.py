import numpy as np

H, W = list(map(int, input().split()))
a = [[] for w in range(W)]

for h in range(H):
    i = input()
    if not '#' in i:
        continue

    for n in range(len(i)):
        a[n].append(i[n])

b = []
for x in a:
    if not '#' in x:
        continue
    b.append(x)

[print(''.join(x)) for x in np.array(b).T.tolist()]
