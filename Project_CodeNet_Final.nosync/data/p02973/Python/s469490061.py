import sys
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7
input=lambda:sys.stdin.readline().rstrip()
from bisect import bisect
def resolve():
    n=int(input())
    A=[-int(input()) for _ in range(n)]
    Q=[]
    for a in A:
        i=bisect(Q,a)
        if(i==len(Q)): Q.append(a)
        else: Q[i]=a

    print(len(Q))
resolve()