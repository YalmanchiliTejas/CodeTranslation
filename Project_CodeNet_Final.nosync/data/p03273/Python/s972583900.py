import numpy as np
h, w = [int(_) for _ in input().split()]

a = np.empty((h, w), dtype=np.str)
for i in range(0, h):
    a[i] = list(input())


height = h
i = 0
while True:
    if i == height:
        break
    if not '#' in a[i]:
        a = np.delete(a, i, axis=0)
        height -= 1
    else:
        i += 1

width = w
i = 0
while True:
    if i == width:
        break
    if not '#' in a[:, i]:
        a = np.delete(a, i, axis=1)
        width -= 1
    else:
        i += 1

for i in range(0, len(a)):
    print(''.join(a[i]))