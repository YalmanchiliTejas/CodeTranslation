import numpy as np
H, W = list(map(int, input().split()))
l = []
for h in range(H):
    l.append(list(input()))
nl = np.array(l)

t = np.all(nl == ".", axis=1)
dl = []
for i, f in zip(range(len(t) + 1), t):
    if f:
        dl.append(i)
nl = np.delete(nl, dl, axis=0)

dl = []
t = np.all(nl == ".", axis=0)
for i, f in zip(range(len(t) + 1), t):
    if f:
        dl.append(i)
nl = np.delete(nl, dl, axis=1)

for s in nl:
    print("".join(s))