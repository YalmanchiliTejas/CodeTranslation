n=int(input())
a=list(map(int,input().split()))
b=sum(a)
ans=0
for i in a:
    ans+=((b-i)*i)%(10**9+7)
print(ans*pow(2,-1,10**9+7)%(10**9+7))