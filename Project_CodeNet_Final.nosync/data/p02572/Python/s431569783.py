import numpy as np
N = int(input())
A = list(map(int, input().split()))
M = 10**9+7

A = np.array(A, np.int64)
a1 = A.sum() % M
a1_sq = a1**2 % M
a2 = (A**2 % M).sum() % M
diff = (a1_sq - a2) % M

if diff % 2 == 0:
    print(diff // 2)
else:
    res = (diff + M) // 2 % M
    print(res)


