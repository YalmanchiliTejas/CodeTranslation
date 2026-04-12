while True:
    n = int(input())
    if n == 0: 
        break
    a, smin, smax=0, 1001, -1
    for i in range(n):
        s = int(input())
        a += s
        if s < smin:
            smin = s
        if s > smax:
            smax = s
        
    print((a-smin-smax)//(n-2))
