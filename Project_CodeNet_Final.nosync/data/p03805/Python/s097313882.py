import copy

def solve():
    N,M = map(int, input().split())
    graph = {i:[] for i in range(1,N+1)}
    for _ in range(M):
        a,b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
        
    stack = [1]
    ret = 0
    searched = [False]*(N+1)
    searched[1] = True
    
    def dfs(dom, searched, prev=-1):
        searched[dom] = True
        ret = 0
        
        if all(searched[1:]): 
            # print(dom,searched,ret)
            return ret+1
        
        for cod in graph[dom]:
            # print(dom,cod)
            if not searched[cod]:
                ret += dfs(cod, copy.copy(searched),dom)
        
        return ret
            
    ret = dfs(1, searched)
    print(ret)
    
solve()