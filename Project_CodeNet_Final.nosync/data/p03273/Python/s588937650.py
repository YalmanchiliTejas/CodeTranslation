import numpy as np


H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]
a = np.array(a)

lst = []
for i, row in enumerate(a):
    if np.all(row=='.'):
        lst.append(i)
a = np.delete(a, lst, 0)
b = a.T
lst = []
for i, row in enumerate(b):
    if np.all(row=='.'):
        lst.append(i)
b = np.delete(b, lst, 0)
ans = b.T
for i in ans:
    print(''.join(i))