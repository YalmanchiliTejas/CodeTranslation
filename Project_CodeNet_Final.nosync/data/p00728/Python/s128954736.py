while True:
    n=int(input())
    if n==0:
        break
    else:
        li=[0]*n
        for i in range(n):
            li[i]=int(input())
        print((sum(li)-max(li)-min(li))//(len(li)-2))
