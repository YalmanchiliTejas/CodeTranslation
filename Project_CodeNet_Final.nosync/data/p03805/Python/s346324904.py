def resolve():
    import sys
    sys.setrecursionlimit(10**6)
    
    N,M = map(int,input().split())
    ab =[map(int,input().split()) for _ in range(M)]
    branch = [[] for _ in range(N)]
    for a,b in ab:
        branch[a-1].append(b-1)
        branch[b-1].append(a-1)
    
    bit = 0
    count = 0
    def walk(p):
        nonlocal bit,N
        bit |= (1 << p)
        if bit == 2 ** N - 1:
            nonlocal count
            count += 1
        for n in branch[p]:
            if not(bit & (1 << n)):
                walk(n)
        bit &= ~(1 << p)

    walk(0)
    print(count)
resolve()