N = int(input())
A = list(map(int,input().split()))
A = A
dp = [[0] * (N+1) for _ in range(N+1)]

for i in range(N+1):
    dp[i][i] = 0

for k in range(1,N+1):#区間の残り数
    for i in range(N):#左端
        x = i+k#右端
        if x > N:
            continue
        elif (N-k) % 2 == 0:#太郎
            #print(i,x)
            dp[i][x] = max(dp[i+1][x] + A[i], dp[i][x-1] + A[x-1])
        elif (N-k) % 2 == 1:#次郎
            #print(i,x)
            dp[i][x] = min(dp[i+1][x] - A[i], dp[i][x-1] - A[x-1])
            
print(dp[0][N])