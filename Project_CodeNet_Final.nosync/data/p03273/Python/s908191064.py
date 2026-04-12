from collections import Counter
import numpy as np
H, W = map(int, input().split())
a = []
r_idx = []
c_idx = []
#a.shape = (H, W)
for i in range(H):
    line = list(input())
    ct = Counter(line).most_common()
    if not (ct[0][1] == W and ct[0][0] == "."):
        r_idx.append(i)
    a.append(line)
a = np.array(a).T
#a.shape = (W, H)
b = []
for i in range(W):
    ct = Counter(a[i]).most_common()
    if ct[0][1] == H and ct[0][0]==".":
        continue
    b.append(a[i])

b = np.array(b).T
c = []
for idx in r_idx:
    c.append(b[idx])

for i in range(len(c)):
    print("".join(c[i]))
