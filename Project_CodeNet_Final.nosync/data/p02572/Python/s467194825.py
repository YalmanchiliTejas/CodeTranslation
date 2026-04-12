n=int(input())
a=list(map(int,input().split()))
s=sum(a)
p=10**9+7
ans=0
for i in range(n):
    s-=a[i]
    ans+=((a[i]%p)*(s%p))%p
    ans%=p
print(ans)