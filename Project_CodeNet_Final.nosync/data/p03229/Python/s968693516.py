N = int(input())
A = [int(input()) for i in range(N)]

A_sorted = sorted(A)
coefficient_yama = [1 for i in range(N)]#上から
coefficient_tani = [-1 for i in range(N)]#下から

for i in range(1,N):
    if i  % 2 == 0:#even
        if N-i >= 2:
            coefficient_yama[i] = +2
            coefficient_tani[i] = -2
        else:
            coefficient_yama[i] = +1
            coefficient_tani[i] = -1
    else:#odd
        if N-i >= 2:
            coefficient_yama[i] = -2
            coefficient_tani[i] = +2
        else:
            coefficient_yama[i] = -1
            coefficient_tani[i] = +1

import numpy as np

ans_tani = np.sum(np.array(A_sorted) * np.array(sorted(coefficient_tani)))
ans_yama = np.sum(np.array(A_sorted) * np.array(sorted(coefficient_yama)))
#print(coefficient_tani)
#print(coefficient_yama)

if ans_tani >= ans_yama:
    print(ans_tani)
else:
    print(ans_yama)
