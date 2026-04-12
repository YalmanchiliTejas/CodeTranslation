N,Q = map(int,input().split())
dp = [0] * (N+2)
dp[2] = 1
ball = 1
for i in range(Q):
    a,b = map(int,input().split())
    dp[a],dp[b] = dp[b],dp[a]
    if ball == a:
        ball = b
    elif ball == b:
        ball = a
    dp[ball-1] |= 1
    dp[ball+1] |= 1
dp[ball] |= 1
print(sum(dp[1:-1]))