n=int(input())
a=list(map(int,input().split()))

x=sum(a)-a[0]
ans=0

for i in range(n):
    ans = (ans + a[i]*x)%(10**9 + 7)
    if i!=n-1:
        x-=a[i+1]
print(ans)
