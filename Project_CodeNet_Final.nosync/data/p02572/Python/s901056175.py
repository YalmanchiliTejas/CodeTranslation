N=int(input())
A=list(map(int, input().split()))
s=sum(A)
m=10**9+7
ans=0
for i in range(N-1):
  s-=A[i]
  ans+=(s*A[i])%m
print(ans%m)