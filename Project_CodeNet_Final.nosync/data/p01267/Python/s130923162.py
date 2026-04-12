while 1:
    n,a,b,c,x=map(int,input().split())
    if n==0:break
    y=list(map(int,input().split()))
    d=[0,1][x==y[0]]
    for i in range(10001):
        if d==n:print(i);break
        x=(a*x+b)%c
        if x==y[d]:d+=1
    else:print(-1)