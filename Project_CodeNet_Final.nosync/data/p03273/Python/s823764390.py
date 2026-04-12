import numpy as np

H, W = map(int,input().split())
G = [list(input()) for i in range(H)]

A = []
for i in G:
    if not '#' in i:
        continue
    A.append(i)

B = np.array(A)
B = B.T

X = []
for i in B:
    if not '#' in i:
        continue
    X.append(i)

ans = np.array(X)
ans = ans.T

for i in ans:
    print(''.join(i))
