N,X,M=map(int,input().split())
Q=0
for i in range(min(100,N)):
  Q+=X
  X=X*X%M
N-=min(N,100)
S=set([X])
P=X
A=X
R=0
for i in range(M):
  A=A*A%M
  if A in S:
    R=i+1
    break
  S.add(A)
  P+=A
P*=(N//R)
N%=R
for i in range(N):
  P+=X
  X=X*X%M
print(P+Q)
