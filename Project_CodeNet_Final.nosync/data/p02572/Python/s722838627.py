N=int(input())
A=list(map(int,input().split()))
S=sum(A)
##print(S)
tmp=0
T=0
for i in range(N-1):
  T=T+A[i]
  ##print(T)
  ##print(A[i])
  tmp=(A[i]*(S-T)+tmp)
tmp=tmp%(10**9+7)
print(tmp)