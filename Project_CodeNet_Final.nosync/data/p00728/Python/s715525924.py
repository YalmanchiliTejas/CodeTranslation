while True:
    n=int(input())
    x=[]
    if n==0:
        break
    else:
        for i in range(n):
            s=int(input())
            x.append(s)
        a=min(x)
        b=max(x)
        ave=(sum(x)-a-b)/(n-2)
        print(int(ave))
