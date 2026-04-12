N = input().strip()
n = len(N)
A = [0 for _ in range(n)]
A[0]=1
for i in range(1,n):
    if N[i]=="0":
        A[i] = A[i-1]
    else:
        A[i] = A[i-1]+1
K = int(input())
if K>n:
    print(0)
else:
    dp = [[[0 for _ in range(n+1)] for _ in range(2)] for _ in range(n+1)]
    dp[0][0][0] = 1
    for i in range(1,n+1):
        for k in range(n+1):
            if k==A[i-1]:
                dp[i][0][k] = 1
                break
    for i in range(1,n+1):
        for k in range(n+1):
            dp[i][1][k] = dp[i-1][1][k]
            if int(N[i-1])>0:
                dp[i][1][k] += dp[i-1][0][k]
            if k>=1:
                dp[i][1][k] += dp[i-1][1][k-1]*9
                if i==1 and k-1==0 and int(N[i-1])>=2:
                    dp[i][1][k] += dp[i-1][0][k-1]*(int(N[i-1])-1)
                elif i>=2 and k-1==A[i-2] and int(N[i-1])>=2:
                    dp[i][1][k] += dp[i-1][0][k-1]*(int(N[i-1])-1)
    print(dp[n][0][K]+dp[n][1][K])