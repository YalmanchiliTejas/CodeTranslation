N = int(input())
A = list(map(int, input().split()))

if N%2==0:
    dp = [[0]*2 for _ in range(N)]
    dp[0][0] = A[0]
    dp[1][1] = A[1]
    
    for i in range(2, N):
        if i==2:
            dp[i][0] = dp[i-2][0]+A[i]
        else:
            dp[i][0] = dp[i-2][0]+A[i]
            dp[i][1] = max(dp[i-3][0]+A[i], dp[i-2][1]+A[i])
    
    print(max(dp[N-2][0], dp[N-1][1]))
else:
    dp = [[0]*3 for _ in range(N)]
    dp[0][0] = A[0]
    dp[1][1] = A[1]
    dp[2][2] = A[2]
    
    for i in range(2, N):
        if i==2:
            dp[i][0] = dp[i-2][0]+A[i]
        elif i==3:
            dp[i][0] = dp[i-2][0]+A[i]
            dp[i][1] = max(dp[i-2][1]+A[i], dp[i-3][0]+A[i])
        else:
            dp[i][0] = dp[i-2][0]+A[i]
            dp[i][1] = max(dp[i-3][0]+A[i], dp[i-2][1]+A[i])
            dp[i][2] = max(dp[i-4][0]+A[i], dp[i-3][1]+A[i], dp[i-2][2]+A[i])
    
    print(max(dp[N-3][0], dp[N-2][1], dp[N-1][2]))