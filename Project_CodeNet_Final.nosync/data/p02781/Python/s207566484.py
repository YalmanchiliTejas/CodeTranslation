N = str(input())
K = int(input())

dp = [[[0]*2 for _ in range(K+1)] for _ in range(len(N)+1)]
dp[0][0][0] = 1

for i in range(len(N)):
  n = int(N[i])
  for j in range(K+1):
    for k in range(2): # smaller(未満なら1)
      for l in range(10): 
        nj, nk = j, 0
        if k == 0 and l == n:
          nk = 0
        elif k == 0 and l < n:
          nk = 1
        elif k == 0 and l > n:
          continue
        
        if k == 1:
          nk = 1
        
        if l != 0:
          if j < K:
            nj += 1
          else:
            continue
        
        dp[i+1][nj][nk] += dp[i][j][k]

print(dp[-1][K][0] + dp[-1][K][1])


        
