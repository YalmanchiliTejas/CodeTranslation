n = int(input())
a = list(map(int, input().split()))

if n%2 == 0:
    dp = a[:2]
    for i in range(1, n//2):
        dp = dp[0] + a[2*i], max(dp) + a[2*i+1]
else:
    dp = a[:3]
    for i in range(1, n//2):
        dp = dp[0] + a[2*i], max(dp[:2]) + a[2*i+1], max(dp) + a[2*i+2]

print(max(dp))