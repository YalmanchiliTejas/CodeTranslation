n,x,m=map(int,input().split())

def f(ai,m):
    return (ai*ai)%m

if x==0:
    print(0)
elif x==1:
    print(n)
elif m==1:
    print(0)
#elif n<=m*2:
#    asum=x
#    ai=x
#    for i in range(1,n):
#        ai=f(ai,m)
#        asum+=ai
#    print(asum)   
else:
    chk=[-1]*m
    asum00=[0]*m
    ai,asum=x,0
    for i in range(m):
        if chk[ai]!=-1:
            icnt0=chk[ai]
            break
        else:
            chk[ai]=i
            asum00[i]=asum
        asum+=ai
        ai=f(ai,m)
    icnt=i
    asum0=asum00[icnt0]
        
    icntk=icnt-icnt0
    n0=n-1-icnt0
    nk=n0//icntk
    nr=n0%icntk
    asumk=asum-asum0

    air,asumr=ai,0
    for i in range(nr):
        asumr+=air
        air=f(air,m)
    asumr+=air
       
    ans=asum0+asumk*nk+asumr    
    print(ans)       
