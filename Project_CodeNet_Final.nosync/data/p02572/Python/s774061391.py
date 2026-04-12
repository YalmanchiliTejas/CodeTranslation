n=int(input())
mod, ans=7+10**9, 0
a=list(map(int, input().split()))
b=[0]
for l in range(n):
    b.append(b[l]+a[l])
for k in range(n-1):
    s=(b[n]-b[k+1])%mod
    ans+=a[k]*s
    ans%=mod
print(ans)