n = int(input())
a = [int(num) for num in input().split()]
dp = [[0,0,0] for _ in range(n//2+1)]

#dp[0] = [a[0],a[1],a[2]]

for i in range(n//2):
    dp[i+1][0] = dp[i][0] + a[i*2]
    dp[i+1][1] = max(dp[i][1],dp[i][0]) + a[i*2+1]
    if n % 2 == 1:
        dp[i+1][2] = max(dp[i][2],dp[i][1],dp[i][0]) + a[i*2+2]
#print(dp)
if n% 2 == 1:
    print(max(dp[-1]))
else:
    print(max(dp[-1][:2]))