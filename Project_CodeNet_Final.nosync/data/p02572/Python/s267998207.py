n=int(input())
a=list(map(int,input().split()))
n=len(a)
mod=10**9+7
su=sum(a)
temp=0
for i in range(n):
    su-=a[i]
    temp+=((a[i]%mod)*su)%mod
print(temp%mod)