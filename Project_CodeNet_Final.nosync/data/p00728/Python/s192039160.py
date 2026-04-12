while True:
    n = int(input())
    if n == 0:
        break
    tensu = []
    for i in range(1,n+1):
        s = int(input())
        tensu.append(s)
    m = min(tensu)
    M = max(tensu)
    tensu.remove(m)
    tensu.remove(M)
    t = len(tensu)
    sum = 0
    for j in range(0,t):
        sum += tensu[j]
    r = sum // t
    print(r)
            

