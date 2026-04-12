N,A,B,C,D=map(int,input().split())
DP=[[0]*(N+1) for i in range(B+1)]
mod=10**9+7

def perm(n,r):
  global mod,g1,g2
  if r<0:
    return g1[n]
  if n<r:
    return 0
  return g1[n]*g2[n-r]%mod

g1=[1,1]
g2=[1,1]
inv=[0,1]
for i in range(2,1000003):
  g1.append((g1[-1]*i)%mod)
  inv.append((-inv[mod%i]*(mod//i))%mod)
  g2.append((g2[-1]*inv[-1])%mod)
DP[A-1][0]=1
for i in range(A,B+1):
  for j in range(N+1):
    DP[i][j]=DP[i-1][j]
    for k in range(C,min(D,j//i)+1):
      DP[i][j]=(DP[i][j]+DP[i-1][j-i*k]*perm((N-j+i*k),i*k)*pow(g2[i],k,mod)*g2[k])%mod
print(DP[B][N])