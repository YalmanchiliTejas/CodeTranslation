N=input()
K=int(input())

l=len(N)
dp0=[[1,0,0,0] for _ in range(l+1)]
dp1=[[0,0,0,0] for _ in range(l+1)]

d=int(N)//10**(l-1)
dp0[0][1],dp1[0][1]=d-1,1

for i,c in enumerate(list(N)[1:]):
  d=int(c)
  for j in range(1,4):
    dp0[i+1][j]=dp0[i][j]+9*dp0[i][j-1]+(dp1[i][j] if d>0 else 0)+((d-1)*dp1[i][j-1] if d>1 else 0)
    dp1[i+1][j]=dp1[i][j-1] if d>0 else dp1[i][j]

print(dp0[l-1][K]+dp1[l-1][K])