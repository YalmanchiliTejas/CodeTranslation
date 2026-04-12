n,m = map(int,input().split())
input_lines = [[int(j)-1 for j in input().split()] for i in range(m)]

map_list = [[] for i in range(n)]

for line in input_lines:
    map_list[line[0]].append(line[1])
    map_list[line[1]].append(line[0])

stack = [[0],]
visited = [0 for i in range(n)]

def dfs(stack,visited):
    if sum(visited)==n:
        return 1
    ans = 0
    
    search = stack.pop(-1)
    for s in search:
        if visited[s]==1:
            continue
        visited[s]=1
        stack.append(map_list[s])
        ans += dfs(stack,visited)
        visited[s]=0
    return ans

ans = dfs(stack,visited)
print(ans)      

