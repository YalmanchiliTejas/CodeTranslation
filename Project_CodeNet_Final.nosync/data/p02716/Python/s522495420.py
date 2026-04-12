N = int(input())
A = list(map(int, input().split()))

dp = [0]*N

cum = A[0]
for i in range(N):
    if i == 0:
        dp[i] = 0
        continue
    if i == 1:
        dp[i] = max(A[0],A[1])
        continue
    if i%2==0: #奇数の時
        cum += A[i]
        dp[i] = max(dp[i-1],dp[i-2]+A[i])

    if i%2==1: #偶数の時
        dp[i] = max(dp[i-2]+A[i],cum)

ans = dp[-1]


print(ans)
#print(*ans, sep='\n')