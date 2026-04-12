while True:
    n=int(input())
    a=[]
    if n==0:
        break
    else:
        for i in range(n):
            a.append(int(input()))
    k=sorted(a)
    del k[0]
    del k[n-2]
    s=sum(k)
    print(int(s/(n-2)))
    
