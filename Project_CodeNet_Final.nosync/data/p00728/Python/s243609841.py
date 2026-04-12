while True:
    
    amax=-1; amin=1001; t=0
    n = int(input())
    if n==0:
        break
    
    for i in range(n):
        a = int(input())
        amax = max(amax,a)
        amin = min(amin,a)
        t += a
    
    print((t-amax-amin)//(n-2))
