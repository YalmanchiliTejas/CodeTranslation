while True:
    a=int(input())
    x=[]
    if a==0:
        break
    else:
        for i in range(a):
            y=int(input())
            x.append(y)
        b=min(x)
        c=max(x)
        ave=(sum(x)-b-c)/(a-2)
        print(int(ave))
