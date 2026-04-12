while True:
    n=int(input())
    if n == 0:
        break
    b=[]
    for i in range(n):
        a=int(input())
        b.append(a)
    c=sorted(b)
    if n == 3:
        print(c[1])
    elif n >= 4:
        d=sum(c)-c[0]-c[n-1]
        e=n-2
        print(d//e)
