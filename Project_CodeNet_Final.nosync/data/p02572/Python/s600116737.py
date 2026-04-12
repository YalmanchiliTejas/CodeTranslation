n=int(input())
l=[int(i) for i in input().split()]
mod=1000000007
suff=[0]*n
suff[-1]=l[n-1]
for i in range(n-2,-1,-1):
    suff[i]=suff[i+1]+l[i]
s=0
for i in range(n-1):
    s=(((suff[i+1]%mod)*l[i])%mod+s)%mod
print(s)