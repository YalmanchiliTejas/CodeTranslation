n,x,m=map(int,input().split())

def f(ai,m):
    return (ai*ai)%m

if x==0:
    print(0)
elif x==1:
    print(n)
elif m==1:
    print(0)
else:
    chk=[-1]*m
    asum00=[0]*m
    ai,asum=x,0
    for icnt in range(m):
        asum00[icnt]=asum
        if chk[ai]!=-1:
            icnt0=chk[ai]
            asum0=asum00[icnt0]
            break
        chk[ai]=icnt
        asum+=ai
        ai=f(ai,m)
        
    icntk=icnt-icnt0
    n0=n-1-icnt0
    nk=n0//icntk
    nr=n0%icntk
    asumk=asum-asum0
       
    ans=asum00[icnt0+nr+1]+asumk*nk
    print(ans)       
