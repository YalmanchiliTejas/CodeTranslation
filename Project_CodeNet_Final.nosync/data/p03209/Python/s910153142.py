N,X=map(int,input().split())
P=[1]
A=[1]
for i in range(N):
  P.append(1+2*P[i])
  A.append(3+2*A[i])
def f(n,x):
  if n==0:
    return 1
  else:
    if x==1:
      return 0
    if 1<x<2+A[n-1]:
      return f(n-1,x-1)
    if x==2+A[n-1]:
      return 1+P[n-1]
    if 2+A[n-1]<x<3+2*A[n-1]:
      return 1+P[n-1]+f(n-1,x-(2+A[n-1]))
    if x==3+2*A[n-1]:
      return 1+2*P[n-1]
print(f(N,X))