n,x,m=map(int,input().split())
ans=x
rp=[x]
if n<=m:
    for i in range(n-1):
        x=pow(x,2,m)
        ans+=x
    print(ans)
    exit()
for i in range(m+1):
    x=pow(x,2,m)
    if x in rp:
        tt=rp.index(x)
        t=len(rp)-tt
        break
    else:
        rp.append(x)
tmp=sum(rp[tt:])
wari=(n-tt)//t
amari=(n-tt)%t
ans=sum(rp[:tt])+tmp*wari+sum(rp[tt:tt+amari])
print(ans)