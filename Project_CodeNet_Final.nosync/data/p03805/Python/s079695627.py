from itertools import permutations

N,M = map(int,input().split())

L = [[] for i in range(N)]

for i in range(M) :
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    
    L[a].append(b)
    L[b].append(a)

P = permutations([0] + [i for i in range(1,N)])

ans = 0

for perm in P :
    visited = [0 for i in range(N)]
    visited[0] = 1
    for i in range(N-1) :
        if perm[i+1] not in L[perm[i]] :
            break
         
        if visited[perm[i+1]] :
            break
        
        visited[perm[i+1]] = 1
    
    if sum(visited) == N :
        ans += 1

print(ans)
