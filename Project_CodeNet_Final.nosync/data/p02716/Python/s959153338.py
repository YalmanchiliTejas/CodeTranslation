import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int,input().split()))

dp = [0]*n
c = a[0]
dp[1] = max(a[0],a[1])

for i in range(2,n):
    if i%2 == 0:
        c += a[i]
        dp[i] = max(dp[i-2]+a[i],dp[i-1])
    else:
        dp[i] = max(dp[i-2]+a[i],c)

print(dp[-1])
    
