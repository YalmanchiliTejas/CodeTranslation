n,x,m=map(int,input().split())
ans=x
a=x
res=[x]
res2=0
r=0
for i in range(1,m+1):
    a=(a*a)%m
    if a==0:
        break
    if a in res:
        r=res.index(a)
        res2=i-r
        break
    else:
        ans+=a
        res.append(a)
b=[0]*m
for i in range(res2):
    b[i+1]=b[i]+res[r+i]
if res2==0:
    print(ans)
else:
    k=(n-r)//res2;l=(n-r)%res2
    ans+=b[res2]*(k-1)+b[l]
    print(ans)
