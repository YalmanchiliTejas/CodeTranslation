while True :
    n=int(input())
    if n==0:
        break
    su,amin,amax=0,1000,0
    for i in range(n):
        a=int(input())
        amin=min(amin,a)
        amax=max(amax,a)
        su+=a
    print((su-amin-amax)//(n-2))
