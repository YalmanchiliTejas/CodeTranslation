n,x,mod=map(int,input().split())
#32 回やればコーナーは回避できる
now=x
xs=0
for i in range(min(n,32)):
    if now%mod==0:print(xs);exit()
    else:
        xs+=now
        now=now*now%mod
        
if x%mod:
    from collections import defaultdict
    d=defaultdict(int)
    su=defaultdict(int)
    s=0
    for i in range(1,n+1):
        if  d[x]:cnt=i;pre=d[x];break
        d[x]=i
        s+=x
        su[i]=s
        x=x**2%mod
    else:print(s);exit()
    length=cnt-pre
    roop=(n-pre)//length
    amari=(n-pre)%length
    once=s-su[pre]+x

    print(su[pre]+roop*once+su[pre+amari]-su[pre-1]-x)


else:print(0)
