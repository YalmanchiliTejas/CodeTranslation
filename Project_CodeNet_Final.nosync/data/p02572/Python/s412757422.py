N=input()
A=list(map(int, input().split()))
mod=10**9+7
g=sum(A)%mod
r=0
for i in A:
  r+=i**2
  r%=mod
ans=(g**2-r)*pow(2,-1,mod)
ans%=mod
print(ans)