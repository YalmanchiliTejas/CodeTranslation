while True:
    n=int(input())
    if n==0:break
    a=0
    mi=1145141919
    ma=0
    for i in range(n):
        t=int(input())
        mi=min(mi,t)
        ma=max(ma,t)
        a+=t
    a-=mi+ma
    print(a//(n-2))
