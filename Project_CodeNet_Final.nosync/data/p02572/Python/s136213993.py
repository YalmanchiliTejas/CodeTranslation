n=int(input())
a=list(map(int,input().split()))
num=sum(a)
mod=10**9+7
ans=0
for i in range(n-1):
    num-=a[i]
    ans+=num*a[i]
    ans%=mod
print(ans)
