n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
cnt=sum(a)
ans=0
for i in range(n):
    ans+=a[i]*(cnt-a[i])
    ans%=mod
    cnt-=a[i]
print(ans)