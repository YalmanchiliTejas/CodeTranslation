import sys
import math
from collections import defaultdict
from bisect import bisect_left, bisect_right

sys.setrecursionlimit(10**7)
def input():
    return sys.stdin.readline()[:-1]

mod = 10**9 + 7

def I(): return int(input())
def LI(): return list(map(int, input().split()))
def LIR(row,col):
    if row <= 0:
        return [[] for _ in range(col)]
    elif col == 1:
        return [I() for _ in range(row)]
    else:
        read_all = [LI() for _ in range(row)]
        return map(list, zip(*read_all))

#################

N = I()
A = LI()


if N%2 == 0:
    d = defaultdict(lambda:defaultdict(lambda:-float('inf')))
    d[0][1] = A[0]
    d[1][1] = max(A[0],A[1])
    for i in range(2,N):
        if i%2 == 0:
            for j in [i//2,i//2+1]:
                d[i][j] = max(d[i-2][j-1]+A[i],d[i-1][j])
        else:
            for j in [(i+1)//2]:
                d[i][j] = max(d[i-2][j-1]+A[i],d[i-1][j])
    print(d[N-1][N//2])
else:
    d = defaultdict(lambda:defaultdict(lambda:-float('inf')))
    d[0][1] = A[0]
    d[1][1] = max(A[0],A[1])
    for i in range(2,N):
        if i%2 == 0:
            for j in [i//2,i//2+1]:
                d[i][j] = max(d[i-2][j-1]+A[i],d[i-1][j])
        else:
            for j in [i//2,i//2+1]:
                d[i][j] = max(d[i-2][j-1]+A[i],d[i-1][j])
    a1 = d[N-1][N//2]
    n = 0
    for i in range(2,N,2):
        n += A[i]
    print(max(n,a1))