# -*- coding: utf-8 -*-
import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
input=lambda: sys.stdin.readline().rstrip()
YesNo=lambda b: print('Yes' if b else 'No')
YESNO=lambda b: print('YES' if b else 'NO')

def main():
    N=int(input())
    A=list(map(int,input().split()))
    dp=[[-INF]*3 for _ in range(N+10)]
    dp[0][0]=0
    for i in range(N+1):
        for j in range(3):
            if j+1<3:
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j])
            if i<N:
                dp[i+2][j]=max(dp[i+2][j],dp[i][j]+A[i])
    if N%2:
        print(dp[N+1][2])
    else:
        print(dp[N+1][1])
    

if __name__ == '__main__':
    main()
