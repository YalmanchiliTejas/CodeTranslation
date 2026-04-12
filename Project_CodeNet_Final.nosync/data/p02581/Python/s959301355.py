import sys
input = sys.stdin.readline

N = int(input().strip())+2
A = list(map(int,input().split()))+[N-1,N]
INF = N
dp = [[-INF for j in range(N)] for i in range(N)]
dpmax = -INF
dpmaxj = [-INF for i in range(N)]
score = 0
a,b,c,d,e = [i-1 for i in sorted(A[:5])]

if a == b == c:
  dp[d][e] = dp[e][d] = dpmaxj[d] = dpmaxj[e] = dpmax = 1
elif b == c == d:
  dp[a][e] = dp[e][a] = dpmaxj[a] = dpmaxj[e] = dpmax = 1
elif c == d == e:
  dp[a][b] = dp[b][a] = dpmaxj[a] = dpmaxj[b] = dpmax = 1
else:
  L = [a,b,c,d,e]
  for i in range(5):
    for j in range(i+1,5):
      p,q = L[i],L[j]
      dp[p][q] = dp[q][p] = dpmaxj[p] = dpmaxj[q] = 0
  dpmax = 0 

def update(i,j):
  dpmaxj[i] = max(dpmaxj[i],dp[i][j])
  dpmaxj[j] = max(dpmaxj[j],dp[i][j])

for i in range(N-3):
  prevdpmax = dpmax
  prevdpmaxj = dpmaxj[:]
  dpd = [dp[k][k] for k in range(N)]
  a,b,c = A[i*3+5:i*3+8]
  a -= 1
  b -= 1
  c -= 1
  prevdpka = [dp[i][a] for i in range(N)]
  prevdpla = [dp[a][i] for i in range(N)] 
  prevdpkb = [dp[i][b] for i in range(N)]
  prevdplb = [dp[b][i] for i in range(N)] 
  if a == b == c:
    score += 1
    continue
  elif a == b:
    for k in range(N):
      dp[k][c] = max(dp[k][c],max(prevdpka[k],prevdpla[k]) + 1)
      dp[c][k] = max(dp[c][k],max(prevdpka[k],prevdpla[k]) + 1)
      dpmax = max(dpmax,dp[k][c],dp[c][k])
      update(k,c)
      update(c,k)
  elif a == c:
    for k in range(N):
      dp[k][b] = max(dp[k][b],max(prevdpka[k],prevdpla[k]) + 1)
      dp[b][k] = max(dp[b][k],max(prevdpka[k],prevdpla[k]) + 1)
      dpmax = max(dpmax,dp[k][b],dp[b][k])
      update(k,b)
      update(b,k)
  elif b == c:
    for k in range(N):
      dp[k][a] = max(dp[k][a],max(prevdpkb[k],prevdplb[k]) + 1)
      dp[a][k] = max(dp[a][k],max(prevdpkb[k],prevdplb[k]) + 1)
      dpmax = max(dpmax,dp[k][a],dp[a][k])
      update(k,a)
      update(a,k)
  dp[b][c] = max(dp[b][c],dpd[a] + 1)
  dp[c][b] = max(dp[c][b],dpd[a] + 1)
  dp[a][c] = max(dp[a][c],dpd[b] + 1)
  dp[c][a] = max(dp[c][a],dpd[b] + 1)
  dp[a][b] = max(dp[a][b],dpd[c] + 1)
  dp[b][a] = max(dp[b][a],dpd[c] + 1)
  dpmax = max(dpmax,dp[b][c],dp[a][c],dp[a][b],dp[c][b],dp[c][a],dp[b][a])
  
  dp[a][b] = max(0,dp[a][b],prevdpmax)
  dp[b][a] = max(0,dp[b][a],prevdpmax)
  dp[b][c] = max(0,dp[b][c],prevdpmax)
  dp[c][b] = max(0,dp[c][b],prevdpmax)
  dp[a][c] = max(0,dp[a][c],prevdpmax)
  dp[c][a] = max(0,dp[c][a],prevdpmax)
  update(a,b)
  update(a,c)
  update(b,a)
  update(b,c)
  update(c,a)
  update(c,b)
  for j in range(N):
    dp[j][a] = max(dp[j][a],prevdpmaxj[j])
    dp[j][b] = max(dp[j][b],prevdpmaxj[j])
    dp[j][c] = max(dp[j][c],prevdpmaxj[j])
    dp[a][j] = max(dp[a][j],prevdpmaxj[j])
    dp[b][j] = max(dp[b][j],prevdpmaxj[j])
    dp[c][j] = max(dp[c][j],prevdpmaxj[j])
    update(j,a)
    update(j,b)
    update(j,c)
    update(a,j)
    update(b,j)
    update(c,j)

print(max(dp[N-2][N-1],dp[N-1][N-2])+score)