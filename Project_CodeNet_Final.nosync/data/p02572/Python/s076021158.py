n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
x=sum(a)%mod
y=0
for i in range(n):
  y+=a[i]**2
  y%=mod
z=pow(2,mod-2,mod)
print(((x**2-y)*z)%mod)