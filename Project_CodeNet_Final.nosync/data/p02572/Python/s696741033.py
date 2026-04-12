n=int(input())
a=list(map(int, input().split()))
s=sum(a)
ans=0
for i in range(n):
    s-=a[i]
    ans=(ans+a[i]*s)%(10**9+7)
print(ans)