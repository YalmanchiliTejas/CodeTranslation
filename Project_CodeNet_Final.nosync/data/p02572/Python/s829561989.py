n=int(input())
a=list(map(int,input().split()))
ans=0
k=sum(a)
for i in a:
    k-=i
    ans+=i*k
print(ans%(10**9+7))