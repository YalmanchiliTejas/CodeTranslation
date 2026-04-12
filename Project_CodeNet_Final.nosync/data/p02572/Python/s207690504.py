n=int(input())
a=list(map(int,input().split()))
mod=10**9+7

tmp=a[-1]
ans=0
for i in range(n-1):
    ii=n-i-2
    #print(ii)
    ans+=(tmp*a[ii])%mod
    ans=ans%mod
    tmp+=a[ii]%mod

print(ans%mod)


    

