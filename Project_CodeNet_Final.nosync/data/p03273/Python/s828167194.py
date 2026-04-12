import numpy as np


h, w = map(int, input().split())
a = []
for i in range(h):
    a.append(list(input()[:]))
a = np.array(a)

n = 0
for i in range(h):
    if all(a[n, :]=='.'):
        a = np.delete(a, n, axis=0)
    else:
        n += 1
n = 0
for i in range(w):
    if all(a[:, n]=='.'):
        a = np.delete(a, n, axis=1)
    else:
        n += 1

for i in range(len(a)):
    for j in range(len(a[0])):
        print(a[i, j], end='')
    print()
