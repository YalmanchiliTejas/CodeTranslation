while True:
    n=int(input())
    if n==0:
        break
    i=1
    sum=0
    max=0
    min=1000
    while i<=n:
        a=int(input())
        if max<a:
            max=a
        if min>a:
            min=a
        sum+=a
        
        
        i+=1
    sum=sum-max-min
    print(int(sum/(n-2)))
