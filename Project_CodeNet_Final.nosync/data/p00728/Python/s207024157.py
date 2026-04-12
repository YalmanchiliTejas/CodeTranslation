while True :
    n=int(input())
    if n==0:break
    ssum=0
    smax=0
    smin=1000
    for i in range(n):
        s=int(input())
        ssum+=s
        if smax<s : smax=s
        if smin>s : smin=s
    print((ssum-smax-smin)//(n-2))
