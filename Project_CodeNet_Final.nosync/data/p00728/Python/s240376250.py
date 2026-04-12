while True:
    n=int(input())
    if n==0:break
    s,vmax,vmin = 0,-1,1001
    for i in range(n):
        a = int(input())
        vmax=max(vmax,a)
        vmin=min(vmin,a)
        s+=a
    print((s-vmax-vmin)//(n-2))
