while True:
    n=int(input())
    if n==0:
        break
    else:
        a=int(input())
        max=a
        min=a
        sum=a
        for i in range(1,n):
            b=int(input())
            sum=sum+b
            if max<b:
                max=b
            elif min>b:
                min=b
        print(int((sum-max-min)/(n-2)))
