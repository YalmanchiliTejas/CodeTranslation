n=int(input())
A=list(map(int,input().split()))
k=sum(A)
c=10**9+7
ans=0
for i in range(n-1):
  k-=A[i]
  ans=(ans+k*A[i])%c
print(ans)