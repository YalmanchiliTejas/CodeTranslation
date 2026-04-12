while True :
    
    n=int(input())
    if n==0 :
        break
    
    i=0
    b=0
    ma=0
    mi=1000
    while i<n :
        c=int(input())
        if ma<c :
            ma=c
        if mi>c :
            mi=c
        b=b+c
        i=i+1
    print(int((b-ma-mi)/(n-2)))
