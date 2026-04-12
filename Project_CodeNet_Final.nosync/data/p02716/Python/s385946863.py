N = int(input())
A = list(map(int,input().split()))
c = 0
if N%2 == 0:
    for i in range(N//2):
        c += A[2*i+1]
    cm = c
    # print(c)
    for i in range(N//2):
        # print(2*i,2*i+1)
        c += A[2*i]-A[2*i+1]
        cm = max(c,cm)
    print(cm)
else:
    dp = [[0]*(3) for _ in range(N//2)]
    # print(dp)
    # 初期化
    dp[0][0] = A[0]
    dp[0][1] = A[1]
    dp[0][2] = A[2]
    for i in range(0,N//2-1):
        dp[i+1][0] = dp[i][0] + A[2*i+2]
        dp[i+1][1] = max(dp[i][0] + A[2*i+3], dp[i][1] + A[2*i+3])
        dp[i+1][2] = max(dp[i][0] + A[2*i+4], dp[i][1] + A[2*i+4], dp[i][2] + A[2*i+4])
    # print(dp)
    print(max(dp[N//2-1][0],dp[N//2-1][1],dp[N//2-1][2]))
