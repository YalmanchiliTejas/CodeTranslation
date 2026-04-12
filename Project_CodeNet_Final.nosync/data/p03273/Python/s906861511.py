import numpy as np

H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]

b = []
for i in range(H):
    if '#' in a[i]:
        b.append(a[i])
b = np.array(b)

c = []
for i in range(W):
    if '#' not in b[:, i]:
        c.append(i)

b = np.delete(b, c, axis=1)

for i in range(len(b)):
    print(*b[i], sep='')
