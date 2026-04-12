import sys
import numpy as np
input = sys.stdin.readline
H, W = map(int, input().split())
a = [list(input().strip()) for _ in range(H)]
a = [ai for ai in a if "#" in ai]
H = len(a)
a_T = np.array(a).T
a_T = [ai for ai in a_T if "#" in ai]
a = np.array(a_T).T
W = len(a[0])
for i in range(H):
    for j in range(W):
        print(a[i][j],end="")
    print("")