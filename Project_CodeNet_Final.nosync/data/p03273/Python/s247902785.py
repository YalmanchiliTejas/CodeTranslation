import numpy as np

h, w = map(int, input().split())
a = np.array([list(input()) for _ in range(h)])

for i in range(h):
    if np.count_nonzero(a[i] == '#') == 0:
        a[i] = 'x'
for i in range(w):
    if np.count_nonzero(a[:, i] == '#') == 0:
        a[:, i] = 'x'

for i in range(h):
    if res := ''.join(filter(lambda x: x != 'x', a[i])):
        print(res)
