while True:
    n=int(input())
    if n==0:
        break
    s=0
    y=[]
    for i in range(1,n+1):
        a=int(input())
        y.append(a)
    ymax=max(y)
    ymin=min(y)
    y.remove(ymax)
    y.remove(ymin)
    ysum=sum(y)
    print(int(ysum/(n-2)))
