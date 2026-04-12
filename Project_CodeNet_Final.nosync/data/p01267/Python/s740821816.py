while True:
    n,a,b,c,x = map(int,input().split())
    if n==0: break
    l = list(map(int,input().split()))
    for i in range(0,10001):
        if l[0]==x:
            del l[0]
            if not(l):
                print(i)
                break
        x = (a*x+b)%c
    else: print(-1)