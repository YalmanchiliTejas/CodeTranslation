mod=998244353
n,s=map(int,input().split())
a=list(map(int,input().split()))
dp=[[0]*(s+1) for _ in range(n+1)]
dp[0][0]=1;ans=0
for i in range(n):
	for j in range(s+1):
		dp[i+1][j]+=dp[i][j]
		dp[i+1][j]%=mod
		if j+a[i]<=s:
			if j==0:
				dp[i+1][a[i]]+=i+1
			else:
				dp[i+1][j+a[i]]+=dp[i][j]
				dp[i+1][j+a[i]]%=mod
		if j+a[i]==s:
			ans+=dp[i+1][j+a[i]]*(n-i)
			ans%=mod
print(ans)
