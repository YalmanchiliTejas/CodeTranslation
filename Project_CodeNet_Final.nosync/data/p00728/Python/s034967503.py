while True:
    n=int(input())
    if n==0:
        break
    else:
        li=[]
        for i in range(n):
            li.append(int(input()))
        b=sum(li)-min(li)-max(li)
        c=n-2
        print(b//c)
