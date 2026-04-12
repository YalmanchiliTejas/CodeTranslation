N,M = map(int,input().split())
ab = [list(map(int,input().split())) for _ in range(M)]

adj = [[] for _ in range(N)]
for a,b in ab:
    adj[a-1].append(b-1)
    adj[b-1].append(a-1)
    

def dfs(x,s,flags):
    vlist = adj[x]
    flags = list(flags)
    flags[x] = False
    flags = tuple(flags)
    if sum(flags) == 0:
        return 1
    s = 0
    for v in vlist:    
        if flags[v]:
            s += dfs(v,s,flags)
    return s        

Flag = [True] * N
Flag[0] = False
ans = dfs(0,0,tuple(Flag))
print(ans)