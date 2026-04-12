import numpy as np
H, W = map(int, input().split())
a = []
for i in range(H):
    ai = input()
    if len(set(ai)) == 1 and ai[0] == '.':
        continue
    else:
        a.append([ai[j] for j in range(len(ai))])
a = np.asarray(a).T
indices = []
for i in range(len(a)):
    if len(set(a[i])) == 1 and a[i][0] == '.':
        continue
    else:
        indices.append(i)
a = a[indices]
for ai in a.T:
    for aij in ai:
        print(aij, end='')
    print()