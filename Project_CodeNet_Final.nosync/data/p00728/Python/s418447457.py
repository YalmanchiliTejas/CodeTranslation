
while True:
    n=int(input())
    m,smin,smax=0,1000,-1
    if n==0:break
    for i in range(n):
        s=int(input())
        smin=min(smin,s)
        smax=max(smax,s)
        m += s
    print((m-smin-smax)//(n-2))
