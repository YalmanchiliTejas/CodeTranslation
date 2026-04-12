import numpy as np

H, W = map(int, input().split())
lst = []
for _ in range(H):
    a = list(input())
    lst.append(a)
lst = np.array(lst)

for i in range(H-1, -1, -1):
    if not '#' in lst[i]:
        lst = np.delete(lst, i, 0)
lst = lst.T
for i in range(W-1, -1, -1):
    if not '#' in lst[i]:
        lst = np.delete(lst, i, 0)
lst = lst.T

for x in lst:
    for y in x:
        print(y, end='')
    print()
