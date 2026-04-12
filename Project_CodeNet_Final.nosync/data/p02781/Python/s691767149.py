N = int(input())
n = str(N)
ln = len(n)
K = int(input())
dp0= [[0] * (K+2) for i in range(ln+1)]
#上からi桁目まで決めて、0でない桁がj個あり、Nより小さいことが確定している
dp1 = [[0] * (K+2) for i in range(ln+1)]
#上からi桁目まで決めて、0でない桁がj個あり、Nより小さいことが確定していない

dp1[0][0] = 1

for i in range(ln):
  x = int(n[i])
  dp0[i+1][0] = 1
  for j in range(K):
    if(x == 0):
      dp0[i+1][j+1] = 9*dp0[i][j]+dp0[i][j+1]
      dp1[i+1][j+1] = dp1[i][j+1]
    else:
      dp0[i+1][j+1] = 9*dp0[i][j]+dp0[i][j+1]+(x-1)*dp1[i][j]+dp1[i][j+1]
      dp1[i+1][j+1] = dp1[i][j]
  #print(dp0)
  #print(dp1)
print(dp0[ln][K]+dp1[ln][K])