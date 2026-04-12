n = int(input())
a = list(map(int, input().split()))
INF = 10 ** 18
if n % 2:
    dp = [[[-INF,-INF,-INF] for i in range(2)] for i in range(n+1)]
    dp[0][0][0] = 0
    # 初期化条件考える
    for i,v in enumerate(a):
        for j in range(2):
            if j:
                dp[i+1][0][0] = max(dp[i+1][0][0],dp[i][1][0])
                dp[i+1][0][1] = max(dp[i+1][0][1],dp[i][1][1])
                dp[i+1][0][2] = max(dp[i+1][0][2],dp[i][1][2])
            else:
                dp[i+1][1][0] = max(dp[i+1][1][0],dp[i][0][0] + v)
                dp[i+1][0][1] = max(dp[i+1][0][1],dp[i][0][0])
                dp[i+1][1][1] = max(dp[i+1][1][1],dp[i][0][1] + v)
                dp[i+1][0][2] = max(dp[i+1][0][2],dp[i][0][1])
                dp[i+1][1][2] = max(dp[i+1][1][2],dp[i][0][2] + v)
    print(max(max(dp[n][0]),max(dp[n][1][1:])))
else:
    odd_sum,even_sum = 0,0
    cumsum = []
    for k,v in enumerate(a):
        if k % 2:
            odd_sum += v
            cumsum.append(odd_sum)
        else:
            even_sum += v
            cumsum.append(even_sum)
    ans = max(cumsum[n-2],cumsum[n-1])
    for i in range(2,n,2):
        ans = max(ans, cumsum[i-2]+cumsum[n-1]-cumsum[i-1])
    print(ans)