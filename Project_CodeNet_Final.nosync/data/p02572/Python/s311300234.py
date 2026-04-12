n=int(input())
a=list(map(int,input().split()))
s=[0]*n
p=sum(a)
for i in range(n):
    p-=a[i]
    s[i]=p
ans=0
for i in range(n):
    ans+=(s[i]*a[i])
    ans=ans%(10**9+7)
print(ans)
