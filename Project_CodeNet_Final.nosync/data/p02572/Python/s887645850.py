N=int(input())
A=list(map(int,input().split()))

temp=sum(A)
ans=0

for i in range(N-1):
  temp-=A[i]
  ans+=A[i]*temp

print(int(ans%(10**9+7)))
