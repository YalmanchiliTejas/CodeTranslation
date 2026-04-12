while True:
    n=int(input())
    if n==0:
        break
    s=0
    vmin=1001
    vmax=-1
    for i in range(n):
        a=int(input())
        vmin=min(vmin,a)
        vmax=max(vmax,a)
        s+=a
    print((s-vmin-vmax)//(n-2))

