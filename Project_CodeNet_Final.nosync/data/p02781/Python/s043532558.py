N = int(input())
K = int(input())
S = [0]+[int(c) for c in str(N)]
L = len(S)-1
dp0 = [[0]*(K+1) for i in range(L+1)]
dp1 = [[0]*(K+1) for i in range(L+1)]
dp0[0][0] = 0
dp1[0][0] = 1
for i in range(1,L+1):
  for j in range(K+1):
    if j==0:
      if S[i]>0:
        dp0[i][j] = dp0[i-1][j]+dp1[i-1][j]
      else:
        dp0[i][j] = dp0[i-1][j]
    else:
      if S[i]>0:
        dp0[i][j] = dp0[i-1][j]+dp0[i-1][j-1]*9+dp1[i-1][j]+dp1[i-1][j-1]*(S[i]-1)
        dp1[i][j] = dp1[i-1][j-1]
      else:
        dp0[i][j] = dp0[i-1][j]+dp0[i-1][j-1]*9
        dp1[i][j] = dp1[i-1][j]
print(dp1[-1][-1]+dp0[-1][-1])
