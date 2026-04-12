def fun(i,j):
	# print(i,j)
	if i>j or i>=n or j<0:
		return 0
	elif i==j:
		dp[i][j]=arr[i]
		return dp[i][j]
	else:
		if dp[i][j]==0:
			dp[i][j]=max(arr[i]+min(fun(i+1,j-1),fun(i+2,j)),arr[j]+min(fun(i+1,j-1),fun(i,j-2)))
		return dp[i][j]
n=int(input())
dp=[0]*n
for i in range(n):
	dp[i]=[0]*n
arr=list(map(int,input().split()))
print(2*fun(0,n-1)-sum(arr))