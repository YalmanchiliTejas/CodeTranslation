while 1:
    m,n=map(int,input().split())
    if m==0:break
    a,i,c=list(range(1,m+1)),0,0
    while i<n:
        i+=1
        b,f=input(),0
        if m<2:continue
        if i%15==0:
            if b!='FizzBuzz':
                del a[c]
                f=1
        elif i%5==0:
            if b!='Buzz':
                del a[c]
                f=1
        elif i%3==0:
            if b!='Fizz':
                del a[c]
                f=1
        elif b!=str(i):
            del a[c]
            f=1
        if f:m-=1
        else:c+=1
        c%=m
    print(*a)