n=int(input())
a=list(map(int,input().split()))
m=10**9+7
s=sum(a)%m
ans=0
for i in a:
    ans+=i*(s-i)
    ans%=m
    s=(s-i)%m
print(ans)
