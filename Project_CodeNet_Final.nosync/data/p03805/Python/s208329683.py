def solve():
    def dfs(node, path, rest):
        if rest == 0:
            nonlocal ans
            ans += 1
        for next_node in adj[node]:
            if next_node not in path:
                dfs(next_node, path + [next_node], rest - 1)
                
    
    from sys import stdin
    f_i = stdin
    
    N, M = map(int, f_i.readline().split())
    
    adj = [[] for i in range(N)]
    for i in range(M):
        a, b = map(int, f_i.readline().split())
        a -= 1
        b -= 1
        adj[a].append(b)
        adj[b].append(a)
    
    ans = 0
    dfs(0, [0], N - 1)
    
    print(ans)

solve()