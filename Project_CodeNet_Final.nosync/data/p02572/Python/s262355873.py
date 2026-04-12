n=int(input())
arr=list(map(int,input().split()))
cum=[0]*n
mod=10**9+7
cum[0]=arr[0]%mod

for i in range(1,n):
    cum[i]=cum[i-1]+arr[i]
    cum[i]%=mod

ans=0
for i in range(n):
    ans+=(arr[i]*((cum[-1]-cum[i])%mod))%mod
    ans%=mod
print(ans)