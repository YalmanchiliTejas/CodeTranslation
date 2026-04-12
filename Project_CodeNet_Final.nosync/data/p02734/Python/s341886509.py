mod=998244353
n,s=map(int,input().split())
a=list(map(int,input().split()))
dp0=[[0]*(s+1) for _ in range(n+1)]
dp1=[[0]*(s+1) for _ in range(n+1)]
dp2=[[0]*(s+1) for _ in range(n+1)]
dp0[0][0]=1
for i in range(n):
	for j in range(s+1):
		dp0[i+1][j]+=dp0[i][j]
		dp1[i+1][j]+=dp0[i][j]+dp1[i][j]
		dp2[i+1][j]+=dp0[i][j]+dp1[i][j]+dp2[i][j]
		dp0[i+1][j]%=mod;dp1[i+1][j]%=mod;dp2[i+1][j]%=mod
		if j+a[i]<=s:
			dp1[i+1][j+a[i]]+=dp1[i][j]+dp0[i][j]
			dp2[i+1][j+a[i]]+=dp1[i][j]+dp0[i][j]
			dp1[i+1][j+a[i]]%=mod;dp2[i+1][j+a[i]]%=mod
print(dp2[n][s])
