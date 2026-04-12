import numpy as np
# import math
# import copy
# from collections import deque
import sys
input = sys.stdin.readline
# sys.setrecursionlimit(10000)
from numba import njit,i8


@njit(i8[:](i8,i8[:],i8[:],i8,i8,i8))
def SerchLoop(M,A,cnt,start,end,temp):
    for i in range(1,M+2):
        temp = A[i-1] ** 2
        temp %= M
        if cnt[temp] != 0:
            start = cnt[temp]
            end = i - 1
            break
        A[i] = temp
        cnt[temp] = i
    return np.append(np.append(A,start),end)


def main():
    N,X,M = map(int,input().split())

    A = [-1 for i in range(M+2)]
    A[0] = X
    A = np.array(A)

    start = -1
    end = -1

    cnt = [0 for i in range(M)]
    cnt[X] = 0
    cnt = np.array(cnt)

    C = SerchLoop(M,A,cnt,start,end,0)
    A = C[:-2]
    start = C[-2]
    end = C[-1]

    L = end - start + 1

    if start == -1:
        straight = [0 for i in range(N)]
        for i in range(N):
            straight[i] = straight[i-1] + A[i]
        res = straight[-1]
    elif start == 0:
        loop = [0 for i in range(L)]
        for i in range(L):
            loop[i] = loop[i-1] + A[start+i]
        res = (N // L) * loop[-1]
        if N % L != 0:
            res += loop[N % L - 1]
    else:
        straight = [0 for i in range(start)]
        for i in range(start):
            straight[i] = straight[i-1] + A[i]
        loop = [0 for i in range(L)]
        for i in range(L):
            loop[i] = loop[i-1] + A[start+i]
        if N >= start:
            res = straight[-1]
            N -= start
        else:
            res = straight[N-1]
            N = 0
        res += (N // L) * loop[-1]
        if N % L != 0:
            res += loop[N % L - 1]

    print(res)



main()
