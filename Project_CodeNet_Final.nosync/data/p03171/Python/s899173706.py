N = int(input())
A = list(map(int,input().split()))

# dp[i][j]:ai~aj残っているときのX-Yの値。(aiのiは0originとする)
# 太朗君の番なのか次郎君の番なのかは、Nと残っているaの個数から判断する。
dp = [[0 for _ in range(N)] for _ in range(N)]

# 漸化式の右辺にi+1,j-1が出てくるから、
# iは小さいほうから、jは大きいほうから決めていく。
for i in range(N-1,-1,-1):
  for j in range(i,N):
    if (N-(j-i))%2 == 1:
      if i == j:
        dp[i][j] = A[i]
      else:
        dp[i][j] = max(A[i]+dp[i+1][j],A[j]+dp[i][j-1])
    else:
      if i == j:
        dp[i][j] = -A[i]
      else:
        dp[i][j] = min(dp[i+1][j]-A[i],dp[i][j-1]-A[j])
print(dp[0][N-1])
