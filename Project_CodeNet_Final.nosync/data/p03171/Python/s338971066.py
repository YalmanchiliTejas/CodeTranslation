#dp[i][j] denotes subarray from i to j left
n=int(input())
l=input().split()
li=[int(i) for i in l]
dp=[[0 for i in range(n)]for i in range(n)]
for i in range(n):
	dp[i][i]=li[i]
for gap in range(1,n):
	for start in range(n-gap):
		end=start+gap
		dp[start][end]=max(li[start]-dp[start+1][end],li[end]-dp[start][end-1])
print(dp[0][n-1])
