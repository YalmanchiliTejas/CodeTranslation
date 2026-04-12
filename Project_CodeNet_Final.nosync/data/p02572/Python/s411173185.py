n=int(input())
a=list(map(int,input().split()))
mod=1000000007
ans=0
s=0
for i in range (n-1):
    if i ==0:
        for j in range(i+1,n):
            s=(s+a[j])%mod
    else:
        s-=a[i]
    ans=(ans+(a[i]*(s))%mod)%mod

print(ans)
