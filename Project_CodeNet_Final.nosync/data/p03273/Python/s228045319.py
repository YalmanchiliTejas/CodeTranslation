import numpy as np

h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

b = []
c = []
cnt = 0

for i in range(h):
    if set(a[i]) != {'.'}:
        b.append(a[i])
        cnt += 1

b = np.array(b)
b =b[::-1,:].T
b = list(b)

for j in range(w):
    if set(b[j]) != {'.'}:
        c.append(b[j])

c = np.array(c)
c = c[::-1,:].T
c = c[::-1,::-1]
c = list(c)

for i in range(cnt):
    print(''.join(map(str, c[i])))