n,m = map(int,input().split())
H = [[0 for _ in range(n)] for _ in range(n) ]

for _ in range(m):
    a, b = map(int,input().split())
    H[a-1][b-1] = 1
    H[b-1][a-1] = 1
    
l = [0 for _ in range(n)]
ans = 0

def dfs(node,visited):
    global ans
    if visited.count(0) == 0:
        ans += 1 
        return 0
    else:
        visited[node] = 1
        for node_,edge_ in enumerate(H[node]):
            if edge_ == 1 and visited[node_] != 1:
                visited[node_] = 1
                visited[node] = 1
                dfs(node_,visited)
                
                #忘れない！！！
                visited[node_] = 0
dfs(0,l)
print(ans)