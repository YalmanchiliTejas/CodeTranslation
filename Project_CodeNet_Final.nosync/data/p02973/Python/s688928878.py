# -*- coding: utf-8 -*-
import sys
from bisect import bisect_left,bisect_right
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
input=lambda: sys.stdin.readline().rstrip()
YesNo=lambda b: bool([print('Yes')] if b else print('No'))
YESNO=lambda b: bool([print('YES')] if b else print('NO'))
int1=lambda x:int(x)-1

def main():
    N=int(input())
    A=[-int(input()) for i in range(N)]
    dp=[INF]*(N+2)
    dp[0]=-INF
    for i in range(N):
        dp[bisect_right(dp,A[i])]=A[i]
    for i in range(N+2):
        if dp[i]==INF:
            print(i-1)
            exit()

if __name__ == '__main__':
    main()
