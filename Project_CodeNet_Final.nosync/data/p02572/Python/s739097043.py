n=int(input())
a=list(map(int,input().split()))
sa=sum(a)
s=0
for i in range(n-1):
    sa-=a[i]
    s+=a[i]*sa
ans=s%(10**9+7)
print(ans)