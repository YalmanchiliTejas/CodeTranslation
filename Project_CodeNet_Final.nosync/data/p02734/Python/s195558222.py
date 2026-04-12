N,S=map(int,input().split())
A= list(map(int,input().split()))
mod=998244353
c=0
M=[[0 for t in range(S+1)] for j in range(N)]
M[0][0]=2
if A[0]<=S:
 M[0][A[0]]=1
if A[0]==S:
 c+=1
for i in range(1,N):
 M[i][0]+=(i+2)
 for k in range(1,S+1):
  M[i][k]+=M[i-1][k]
  M[i][k]%=mod
  if k>=A[i] :
   M[i][k]+=M[i-1][k-A[i]]
   M[i][k]%=mod
 c+=M[i][S]
 c%=mod
print(c)
