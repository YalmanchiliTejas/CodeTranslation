import sys
input = sys.stdin.readline
n = int(input())
a = [int(i) for i in input().split()]
if n <= 3:
  print(max(a))
  exit()

a = tuple(a)
dp = [[-10**15]*3 for i in range(n)]

dp[0][2] = a[0]
dp[1][2] = a[1]
dp[2][2] = a[0]+a[2]
dp[3][2] = max(a[0],a[1])+a[3]
dp[3][1] = a[0]+a[3]
for i in range(2,n-2):
  if i%2 == 0:
    dp[i+2][2] = dp[i][2]+a[i+2]
    dp[i+2][0] = max(dp[i][0]+a[i+2],dp[i-1][1]+a[i+2],dp[i-2][2]+a[i+2])
  else:
    dp[i+2][2] = max(dp[i][2],dp[i][1],dp[i-1][2])+a[i+2]
  dp[i+2][1] = max(dp[i][1]+a[i+2],dp[i-1][2]+a[i+2])
if n%2 == 1:
  c = min(a[0],a[-1])
  dp[n-1][2] -= c
print(max(dp[n-1][0],dp[n-1][1],dp[n-1][2]))
