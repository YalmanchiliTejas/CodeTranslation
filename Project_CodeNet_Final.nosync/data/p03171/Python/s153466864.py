MAX_INT = 100

N = int(input())
a = list(map(int,input().split()))

dp = [[0]*(N) for i in range(N+1)]

if  N%2 == 0:
  hand = 0
else:
  hand = 1

for i in range(N):
  if hand == 0:
    dp[i][i] = -a[i]
  else:
    dp[i][i] = a[i]
  
for i in range(1,N+1):
  for j in range(N+1):
    if i+j < N:
      if (hand+i)%2 == 1: # 先手
        dp[j][i+j] = max(dp[j][i+j-1]+a[i+j],dp[j+1][i+j]+a[j])
      else:
        dp[j][i+j] = min(dp[j][i+j-1]-a[i+j],dp[j+1][i+j]-a[j])
    else:
      break  
print(dp[0][-1])