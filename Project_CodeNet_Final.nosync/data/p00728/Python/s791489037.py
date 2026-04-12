while True :
    n = int(input())
    P = []
    
    if n == 0 :
        break
    else :
        for i in range(n) :
            P.append(int(input()))
        
        Ps = sorted(P)
        del Ps[0]
        del Ps[n - 2]
        s = sum(Ps)
        
        print(s // (n - 2))
