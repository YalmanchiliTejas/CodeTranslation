import sys
sys.setrecursionlimit(10**6)

N = int(input())
ali = list(map(int,input().split()))
inf = 10**15
dp = [[inf]*(N+1) for _ in range(N+1)]
#i-j番目までが残っているときの利益の最大値
for i in range(N+1):
  dp[i][i] = 0

for j in range(1,N+1):
  for i in range(N+1):
    if i+j > N:
      break
    dp[i][i+j] = max(-dp[i+1][i+j]+ali[i],-dp[i][i+j-1]+ali[i+j-1])
  
print(dp[0][N])