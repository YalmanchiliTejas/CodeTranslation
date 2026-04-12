N=int(input())
A=list(map(int,input().split()))

ans=sum(A)%(2*(10**9+7))
ans=ans**2%(2*(10**9+7))

for i in range(N):
  ans-=A[i]**2
  ans=ans%(2*(10**9+7))

print(ans//2%(10**9+7))