n,x,m=map(int,input().split())
a=list()
ans=0
s=n
for i in range(n):
    ans+=x
    a.append(x)
    x=(x**2)%m
    if x in a:
        s=a.index(x)
        break

sum=0
if s!=n:
    for i in range(s, len(a)):
        sum+=a[i]   

if len(a)>s:
    ans+=sum*(((n-s)//(len(a)-s))-1)

    z=(n-s)%(len(a)-s)
    if z!=0:
        for i in range(z):
            ans+=a[s+i]
print(ans)
