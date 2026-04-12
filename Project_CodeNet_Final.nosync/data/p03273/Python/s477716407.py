#!/usr/bin/env python3
import numpy as np

h, w = list(map(int, input().split()))

a = np.array([list(input()) for i in range(h)])

need_h = []
need_w = []
for i in range(h):
    tmp = a[i, :].tolist()
    if set(tmp) != set(["."]):
        need_h.append(i)

# print(a)
for i in range(w):
    tmp = a[:, i].tolist()
    if set(tmp) != set(["."]):
        need_w.append(i)
# print(need_w)

# print(need_h)
# print(need_w)
ans = np.take(np.take(a, need_h, axis=0), need_w, axis=1)

for i in ans:
    print("".join(i.tolist()))
