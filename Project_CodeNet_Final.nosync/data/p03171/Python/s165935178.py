N = int(input())
A = list(map(int,input().split()))
dp = [[0] * (N+1) for _ in range(N+1)]

#半開区間で考える⇒[i,j)での最適解
for w in range(1,N+1):#区間の残り数
    for l in range(N):# 左端
        r = l + w#右端
        if r > N:
            continue
        elif (N-w) % 2 == 0:#太郎
            dp[l][r] = max(dp[l+1][r] + A[l], dp[l][r-1] + A[r-1])
        elif (N-w) % 2 == 1:#次郎
            dp[l][r] = min(dp[l+1][r] - A[l], dp[l][r-1] - A[r-1])
            
print(dp[0][N])