n=int(input())
a=list(map(int,input().split()))
s=sum(a[1:])
ans=0
for i in range(1,n):
    ans+=a[i-1]*s
    s-=a[i]
print(ans%(10**9+7))
