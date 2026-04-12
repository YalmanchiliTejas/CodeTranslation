n = int(input())
a= list(map(int, input().split()))
s=sum(a)
INF=1000000007
ans=0

for i in range(n-1):
    s-=a[i]
    ans+=a[i]*s
    ans%=INF
print(ans)
