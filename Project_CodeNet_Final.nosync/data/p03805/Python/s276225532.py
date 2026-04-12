from copy import copy
n, m = map(int,input().split())
ab = [[0 for i in range(n)] for j in range(n)]
for i in range(m):
    ai,bi = map(int,input().split())
    ab[ai-1][bi-1] = 1
    ab[bi-1][ai-1] = 1

count = 0

def dfs(x,v):
    l = copy(v)
    l.append(x)
    if len(l)==n:
        global count
        count += 1
    for i in range(n):
        if ab[x][i] == 1 and not i in l:
            dfs(i,l)
    
dfs(0,[])
print(count)