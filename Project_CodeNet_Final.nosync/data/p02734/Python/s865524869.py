# -*- coding: utf-8 -*-
import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=998244353
def input(): return sys.stdin.readline().rstrip()

def main():
    N,S=map(int,input().split())
    A=list(map(int,input().split()))
    dp0=[[0 if i!=0 else 1 for i in range(S+1)] for _ in range(N+1)]
    dp1=[[0]*(S+1) for _ in range(N+1)]
    dp2=[[0]*(S+1) for _ in range(N+1)]
    for i in range(N):
        for j in range(S+1):
            b=int(j==0)
            dp1[i+1][j]+=dp1[i][j]+b
            dp2[i+1][j]+=dp1[i][j]+dp2[i][j]+b
            dp1[i+1][j]%=MOD
            dp2[i+1][j]%=MOD
            if j+A[i]<=S:
                dp1[i+1][j+A[i]]+=dp1[i][j]+b
                dp2[i+1][j+A[i]]+=dp1[i][j]+b
                dp1[i+1][j+A[i]]%=MOD
                dp2[i+1][j+A[i]]%=MOD
    print(dp2[-1][-1])

if __name__ == '__main__':
    main()
