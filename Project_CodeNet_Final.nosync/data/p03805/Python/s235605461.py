def read_int_list():
    return list(map(int,input().split()))
    
N, M = read_int_list()
g = [[] for i in range(N)]

for i in range(M):
    a,b = read_int_list()
    a-=1
    b-=1
    g[a].append(b)
    g[b].append(a)
    
def dfs(v):
    if len(v) == N:return 1
    ans=0
    for u in set(g[v[-1]]) - set(v):
        ans += dfs(v + [u])
    return ans
print(dfs([0]))