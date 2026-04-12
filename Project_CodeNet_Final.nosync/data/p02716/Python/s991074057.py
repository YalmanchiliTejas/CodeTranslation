from math import gcd
from functools import reduce
 
n=int(input())
ar=list(map(int,input().split(' ')))
 
dp=[[-(10**20)]*6 for i in range(n+5)]+[[0]+[-(10**20)]*8 for i in range(3)]
 
 
#1> 2 3> 4  6> 7 8> 9 10 11> 12> 14
def cn(z,j):
	return (z-j+1)//2
ans=-(10**20)
for i in range(n):
	idx=int(i)
	dp[idx]=dp[idx-2].copy()
	for j in range(0,5):
			for k in range(j+1):
					dp[idx][j]=max(dp[idx][j],dp[idx-k-2][j-k])
	for j in range(5):
		dp[i][j]+=ar[i]
		if cn(i+1,j)==n//2:
			ans=max(ans,dp[i][j])
print(ans)

