while True:
    n=int(input())
    if n == 0 : break
    a,b,c=0,1001,-1
    for i in range(n):
        m=int(input())
        b=min(b,m)
        c=max(c,m)
        a+=m
    print((a-b-c)//(n-2))
