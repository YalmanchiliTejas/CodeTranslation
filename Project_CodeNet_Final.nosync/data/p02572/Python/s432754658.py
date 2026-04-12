n=int(input())
a=list(map(int,input().split()))
mod=1000000007
sum=0
tmp=0
o=0
while(o<n):
    tmp = (a[o]%mod + tmp%mod)%mod
    o += 1

for i in range(n):
    tmp=(tmp%mod-a[i]%mod)%mod
    sum=((a[i]%mod)*tmp)%mod+sum%mod



print(sum%mod)
