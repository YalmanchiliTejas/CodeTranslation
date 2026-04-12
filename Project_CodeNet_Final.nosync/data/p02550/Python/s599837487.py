n,x,m=map(int,input().split())

def f(ai,m):
    return (ai*ai)%m

if x==0:
    print(0)
elif x==1:
    print(n)
elif m==1:
    print(0)
elif n<=m*2:
    asum=x
    ai=x
    for i in range(1,n):
        ai=f(ai,m)
        asum+=ai
    print(asum)   
else:
    aa=[]
    ai,icnt,asum=x,0,0
    while not ai in aa:
        asum+=ai
        aa.append(ai)
        ai=f(ai,m)
        icnt+=1
    ai0,icnt0,asum0=x,0,0
    if ai!=x:
        for i in range(icnt+1):
            asum0+=ai0
            ai0=f(ai0,m)
            icnt0+=1
            if ai0==ai:
                break
    icntk=icnt-icnt0
#    print("1:",ai,asum,icnt,ai0,asum0,icnt0)
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
