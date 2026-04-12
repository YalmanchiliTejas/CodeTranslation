import sys
input = sys.stdin.readline
H, W = [int(x) for x in input().split()]
a = []
for _ in range(H):
    a.append(list(input().rstrip()))
import numpy as np
a = np.array(a, np.object)
a = a.T
retsu = []
gyou = []
for i in range(W):
    if "#" not in a[i]:
        retsu.append(i)
a = a.T
for i in range(H):
    if "#" not in a[i]:
        gyou.append(i)
a = np.delete(a, retsu, 1)
a = np.delete(a, gyou, 0)
for j in a:
    j = list(j)
    print("".join(j))