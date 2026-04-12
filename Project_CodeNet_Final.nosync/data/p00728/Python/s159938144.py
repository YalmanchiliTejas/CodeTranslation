while True:
    n=int(input())
    if n==0:
        break
    x=[]
    for i in range(n):
        y=int(input())
        x.append(y)
    x.sort()
    x.pop(n-1)
    x.pop(0)
    b=sum(x)//len(x)
    print(b)
