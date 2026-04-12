import numpy as np
h, w = map(int, input().split())
ary = np.array([list(input()) for _ in range(h)])

d_h = []
d_w = []
for i in range(h):
    if "#" not in ary[i]:
        d_h.append(i)
for i in range(w):
    if "#" not in ary[:,i]:
        d_w.append(i)

ary = np.delete(ary, d_h, 0)
ary = np.delete(ary, d_w, 1)

for a in ary:
    print("".join(a))