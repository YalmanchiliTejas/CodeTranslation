n = int(input())
a = list(map(int,input().split()))

# i個使う時の要素の和の最大値
dp = [0]*(n+1)
dp[1] = 0
dp[2] = max(a[0],a[1])

# 奇数の番号の累積和
b = [0]*(n+1)
b[1] = a[0]
for i in range(1,n-1,2):
    b[i+2] = b[i] + a[i+1]
# print(b)

for i in range(3,n+1):
    if i % 2 == 0:
        dp[i] = max(dp[i-2] + a[i-1], b[i-1])
    else:
        dp[i] = max(dp[i-2] + a[i-1], dp[i-3] + a[i-2], b[i-2])

# print(dp)
print(dp[n])