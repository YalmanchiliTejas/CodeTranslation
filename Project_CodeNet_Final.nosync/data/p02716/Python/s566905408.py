n = int(input())
a = list(map(int, input().split()))

if n == 2:
    print(max(a[0], a[1]))
    exit()
elif n == 3:
    ans = max(a[0], a[1])
    print(max(ans, a[2]))
    exit()

if n % 2 == 0:
    inf = - float('inf')
    dp = [[inf, inf] for _ in range(n)]
    dp[0][0] = a[0]
    dp[1][1] = a[1]
    dp[2][0] = a[0] + a[2]

    for i in range(3, n):
        if i % 2 == 0:
            dp[i][0] = dp[i - 2][0] + a[i]
        dp[i][1] = max(dp[i - 3][0], dp[i - 2][1]) + a[i]

    #print(dp)
    print(max(dp[n-1][1], dp[n-2][0]))
    exit()

inf = - float('inf')
dp = [[inf, inf, inf] for _ in range(n)]
dp[0][0] = a[0]
dp[1][1] = a[1]
dp[2][0] = a[0] + a[2]
dp[2][2] = a[2]
dp[3][1] = max(a[0], a[1]) + a[3]

for i in range(4, n):
    if i % 2 == 0:
        dp[i][0] = dp[i-2][0] + a[i]
    dp[i][1] = max(dp[i-3][0], dp[i-2][1]) + a[i]
    temp = max(dp[i-4][0], dp[i-3][1])
    dp[i][2] = max(temp, dp[i-2][2]) + a[i]

ans = max(dp[n-1][2], dp[n-2][1])
print(max(ans, dp[n-3][0]))