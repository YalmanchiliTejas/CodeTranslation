n = int(input())
a = list(map(int, input().split()))

if n==2:
    print(max(a))
    exit()

dp = [0]*n
ep = [0]*n

dp[1] = max(a[:2])
dp[2] = max(a[:3])

ep[1] = a[0]
ep[2] = max(a[:2])

for i in range(3,n):
    if (i+1)%2==0:
        ep[i] = ep[i-2] + a[i-1]
    else:
        ep[i] = max(ep[i-2]+a[i-1],ep[i-3]+a[i-2])
    dp[i] = max(dp[i-2]+a[i],ep[i])

print(dp[-1])