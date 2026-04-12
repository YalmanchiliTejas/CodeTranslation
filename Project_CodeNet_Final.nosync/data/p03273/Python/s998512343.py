import numpy as np
h,w = map(int, input().split())
a = []
for i in range(h):
    b = list(input())
    if b.count('.') == w:
        continue
    else:
        a.append(b)
c = np.array(a)
d = c.T
e = d.tolist()
f = []
for i in range(d.shape[0]):
    if e[i].count('.') == d.shape[1]:
        f.append(i)
f.sort(reverse = True)
for i in f:
    d = np.delete(d, i, 0)
ans = d.T.tolist()
for i in range(len(ans)):
    print(''.join(ans[i]))