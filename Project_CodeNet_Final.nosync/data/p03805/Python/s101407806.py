from itertools import permutations

N,M = map(int,input().split())

A = [[0]*N for i in range(N)]

for i in range(M) :
    u,v = map(int,input().split())
    u -= 1
    v -= 1
    
    A[u][v] = 1
    A[v][u] = 1

ran = list(range(1,N))

P = list(permutations(ran))

ans = 0

for perm in P :
    perm = list(perm)
    
    for u,v in zip([0]+perm, perm) :
        if not A[u][v] :
            break
        
    else :
        ans += 1

print(ans)
