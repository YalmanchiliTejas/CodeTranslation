n=int(input())
a=list(map(int,input().split()))
ans=0
s=sum(a)
for i in range(n-1):
    ans+=a[i]*(s-a[i])
    s-=a[i]
print(ans%1000000007)