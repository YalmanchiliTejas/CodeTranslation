from itertools import permutations as pmt

N,M = [int(x) for x in input().split()]

import numpy as np
Mat = [[0 for i in range(N)] for j in range(N)]
for i in range(M):
    a,b = [int(x) for x in input().split()]
    Mat[a-1][b-1] = 1

Mat = np.array(Mat)
Mat += Mat.T

ans = 0
for od in pmt([i for i in range(1,N)]):
    order = [0] + list(od)
    ok = True
    for i in range(N-1):
        ok &= (Mat[order[i]][order[i+1]] > 0)
    ans += int(ok)    

print(ans)