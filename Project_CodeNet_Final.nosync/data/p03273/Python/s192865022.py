h, w = map(int, input().split())
a = []
for _ in range(h):
    _a = list(input())
    if '#' in _a:
        a += [_a]
    else:
        pass

import numpy as np

a = np.array(a)
ans_col = []

for i in range(w):
    if '#' in a[:,i]:
        ans_col += [i]
    else:
        pass

ans = a[:, ans_col]

for j in range(a.shape[0]):
    print(''.join(map(str, ans[j, :])))
