N=int(input())
A=list(map(int,input().split()))
S=sum(A)%(10**9+7);T=0
for i in range(N-1):
  T=T+(A[i]%(10**9+7)*(S-A[i]%(10**9+7)))
  S=S-A[i]%(10**9+7)
  #print(i,T)
print(T%(10**9+7))