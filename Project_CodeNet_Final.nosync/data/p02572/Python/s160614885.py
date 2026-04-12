N=int(input())
A=list(map(int,input().split()))
SUM=sum(A)
res=0
for i in range(N) :
  SUM-=A[i]
  res+=A[i]*SUM
print(res%(10**9+7))