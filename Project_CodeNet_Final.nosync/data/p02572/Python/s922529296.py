n=int(input())
a=list(map(int,input().split()))
s=sum(a)
ans=0
for val in a:
    s-=val
    ans+=s*val
ans%=(10**9+7)
print(ans)
