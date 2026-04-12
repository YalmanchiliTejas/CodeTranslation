n = list(map(int, list(input())))
k = int(input())

dp = [[0,0,0] for _ in range(len(n))]
counter = 0

for i in range(len(n)):
    dp[i][0] += dp[i-1][0] + 9*(counter > 0)
    dp[i][1] += dp[i-1][0]*9 + dp[i-1][1]
    dp[i][2] += dp[i-1][1]*9 + dp[i-1][2]
    if n[i] > 0:
        if counter >= 1 and counter <= 3:
            dp[i][counter-1] += 1
        counter += 1
        if counter <= 3:
            dp[i][counter-1] += n[i]-1

print(dp[len(n)-1][k-1]+(counter==k))