from itertools import permutations

N,M = map(int,input().split())

L = [[False for j in range(N)] for i in range(N)]

for i in range(M) :
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    
    L[a][b] = True
    L[b][a] = True

P = list(permutations(range(1,N)))

ans = 0

for perm in P :
    perm = list(perm)
    
    for s,g in zip([0] + perm, perm) :
        if not L[s][g] :
            break
    else :
        ans += 1

print(ans)
        