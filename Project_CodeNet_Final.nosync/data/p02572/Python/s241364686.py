n=int(input())
a=list(map(int,input().split()))
su=sum(a)
com=0
mod=pow(10,9)+7
for i in range(n):
  su=max(0,su-a[i])
  com+=(su*a[i])%mod

print(com%mod)