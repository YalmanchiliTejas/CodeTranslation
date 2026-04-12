from bisect import*
INF=10**18
n=int(input())
dp=[-1]*n
for _ in range(n):
  i=int(input())
  dp[bisect_left(dp,i)-1]=i
print(sum([i>=0 for i in dp]))