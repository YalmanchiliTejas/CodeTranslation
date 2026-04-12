n,x,m=map(int,input().split())

f=1
w=[]
d=[0]*(m+2)
t=[0]
chk=n
p=x
for i in range(m+1):
    if i!=0: p=p*p%m
    if d[p]: break
    d[p]=1
    w.append(p)
    t.append(t[-1]+p)
    #f*=2
    chk-=1
    if chk==0:
        print(t[-1])
        exit()
ans=0
a=w.index(p)
ans+=t[a]
n-=a
loo=len(w)-a
if n%loo==0:
    ans+=(t[-1]-t[a])*(n//loo)
else:
    ans+=(t[-1]-t[a])*(n//loo)
    ans+=t[a+n%loo]-t[a]
print(ans)