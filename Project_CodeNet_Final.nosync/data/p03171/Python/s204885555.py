# -*- coding: utf-8 -*-
import sys

N=input()
A=map(int, sys.stdin.readline().split())

dp=[ [ None for i in range(N) ]  for j in range(N) ]


for i in range(N-1,-1,-1):
	if N%2==0:
		dp[i][i]=A[i]*-1
	else:
		dp[i][i]=A[i]


for i in range(N-2,-1,-1):
	for j in range(i+1,N):
		t=N-(j-i+1)	#残りの要素数
		if t%2==0:
			if dp[i][j] is None : dp[i][j]=float("-inf")
			dp[i][j]=max(dp[i][j] , dp[i][j-1]+A[j])
			dp[i][j]=max(dp[i][j] , dp[i+1][j]+A[i])
		else:
			if dp[i][j] is None : dp[i][j]=float("inf")
			dp[i][j]=min(dp[i][j] , dp[i][j-1]-A[j])
			dp[i][j]=min(dp[i][j] , dp[i+1][j]-A[i])

print dp[0][N-1]
