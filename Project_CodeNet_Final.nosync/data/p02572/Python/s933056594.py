n=int(input())
ans=0
mod=10**9+7
s=list(map(int,input().split()))
cs=0
for i in s:
    ans=(ans+cs*i)%mod
    cs=(cs+i)%mod
print(ans)