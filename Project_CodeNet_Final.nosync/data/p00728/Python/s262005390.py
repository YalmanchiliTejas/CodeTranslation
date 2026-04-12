while True:
    
    n=int(input())
    if n==0:
        break
    
    list=[]
    for x in range(n):
        x=int(input())
        list.append(x)
        a=sum(list)
        b=min(list)
        c=max(list)
    print((a-b-c)//(n-2))
