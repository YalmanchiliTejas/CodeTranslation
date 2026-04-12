n=int(input())
l=[int(x) for x in input().split()]
dp=[[0 for i in range(n+1)] for j in range(n+1)] 
for i in range(n-1,-1,-1):
	for j in range(0,n,1):
		if i==j:
			dp[i][j]=l[i]
		else:
			dp[i][j]=max(l[i]-dp[i+1][j],l[j]-dp[i][j-1])
		#print(i,j)

#print(dp)
print(dp[0][n-1])