import bisect
n = int(input())
a = [int(input()) for _ in range(n)]
dp = [float('inf')]*n
for i in range(n):
  c = a[n-i-1]
  b = bisect.bisect_right(dp,c)
  if dp[b] > c:
    dp[b] = c
print(bisect.bisect_right(dp,10**9+1))