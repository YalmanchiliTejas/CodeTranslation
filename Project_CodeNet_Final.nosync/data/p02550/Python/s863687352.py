
n,x,m=map(int,input().split())

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
        ai=(ai*ai)%m
        asum+=ai
    print(asum)   
else:
    aa=[]
    ai=x
    icnt=0
    asum=0
    while not ai in aa:
        asum+=ai
        aa.append(ai)
        ai=(ai*ai)%m
        icnt+=1
    asum0=0
    ai0=x
    icnt0=0
    if ai!=x:
        for i in range(icnt+1):
            asum0+=ai0
            ai0=(ai0*ai0)%m
            icnt0+=1
            if ai0==ai:
                break
    icntk=icnt-icnt0
    if icntk==0:
        print("0:",ai,asum,icnt,ai0,asum0,icnt0)
        icntk=1
        n0=n-1
        nk=n0//icntk
        nr=0
        asumk=ai0
        asumr=0
        ans=asum0+x*(n-icnt0)
        print(ans)       
    else:
#        print("1:",ai,asum,icnt,ai0,asum0,icnt0)
        n0=n-1-icnt0
        nk=n0//icntk
        nr=n0%icntk
        asumk=asum-asum0
        asumr=0
        air=ai
        for i in range(nr):
            asumr+=air
            air=(air*air)%m
        asumr+=air
       
        ans=asum0+asumk*nk+asumr    
        print(ans)       
        
