from collections import *
import sys
inp = raw_input

def err(s):
    sys.stderr.write('{}\n'.format(s))

def ni():
    return int(inp())

def nl():
    return [int(_) for _ in inp().split()]

def lis(X):
    N = len(X)
    P = [0]*N
    M = [0]*(N+1)
    L = 0
    for i in range(N):
        lo, hi = 1, L + 1
        while lo < hi:
            mid = (lo + hi) >> 1
            if X[M[mid]] >= X[i]:
                lo = mid + 1
            else:
                hi = mid
        newL = lo
        P[i] = M[newL - 1]
        M[newL] = i
        L = max(L, newL)
    S = [0]*L
    k = M[L]
    for i in range(L-1, -1, -1):
        S[i] = X[k]
        k = P[k]
    return S

N = ni()
A = [ni() for _ in range(N)]

print(len(lis(A)))
