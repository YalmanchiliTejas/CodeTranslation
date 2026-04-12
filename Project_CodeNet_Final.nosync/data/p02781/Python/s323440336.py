n=input()
k=int(input())
keta=len(n)
#桁dp
#dp0 n以下確定
#dp1 未確定
#dp[桁][個数]
dp0=[[0]*(k+1) for _ in range(keta)]
dp1=[[0]*(k+1) for _ in range(keta)]
dp0[0][0]=1
dp0[0][1]=int(n[0])-1
dp1[0][1]=1
for i in range(1,keta):
	# if n[i]=="0":
	# 	for j in range(k+1):
	# 		dp1[i][j]=dp1[i-1][j]
	# 	dp0[i][0]=dp0[i-1][0]
	# 	for j in range(k+1):
	# 		dp0[i][j]=dp0[i-1][j-1]*9+dp0[i-1][j]
	if n[i]=="0":
		conf=dp0
		notconf=dp1
		for j in range(k+1):
			notconf[i][j]=notconf[i-1][j]
		conf[i][0]=conf[i-1][0]
		for j in range(1,k+1):
			conf[i][j]=9*conf[i-1][j-1]+conf[i-1][j]
	else:
		for j in range(1,k+1):
			dp1[i][j]=dp1[i-1][j-1]
		dp0[i][0]=dp0[i-1][0]
		for j in range(1,k+1):
			dp0[i][j]=dp1[i-1][j]+dp1[i-1][j-1]*(int(n[i])-1)+dp0[i-1][j-1]*9+dp0[i-1][j]
print(dp0[-1][k]+dp1[-1][k])



