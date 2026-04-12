N=int(input())
L=list(map(int,input().split()))
ans=0
a=sum(L)
mod=1000000007
for i in range(N):
  ans+=L[i]*(a-L[i])
  ans%=mod
if ans%2==0:
  print(ans//2)
else:
  print((ans+mod)//2)