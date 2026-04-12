while True:
    n=int(input())
    if n==0:
        break
    i,min,max,a=0,1000,0,0
    while i<n:
        s=int(input())
        a+=s
        if min>s:
            min=s
        if max<s:
            max=s
        i+=1
    print((a-min-max)//(n-2))
