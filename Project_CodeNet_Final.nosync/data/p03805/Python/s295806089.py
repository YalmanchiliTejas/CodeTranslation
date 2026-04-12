N,M = map(int, input().split())

A = [[] for j in range(N)]
for i in range(M):
    a,b = map(int, input().split())
    A[a-1].append(b-1)
    A[b-1].append(a-1)
    

D = [0]*N
C = 0
D[0] = 1

def dfs(x):
    global C
    
    if not 0 in D:
        C += 1
        return
    
    for i in A[x]:
        if D[i] == 1:
            continue
        D[i] = 1
        dfs(i)
        D[i] = 0

dfs(0)
print(C)