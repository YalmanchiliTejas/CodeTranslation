N,M = map(int,input().split())
branch_list = []
for i in range(M):
    branch_list.append(list(map(int,input().split())))

visited = [1]

def dfs(now):
    global cnt
    if len(visited) == N:
        cnt += 1
        return cnt
    for br in branch_list:
        if now in br:
            next_node = br[1-br.index(now)]
            if not next_node in visited:
                visited.append(next_node)
                dfs(next_node)
                visited.remove(next_node)
    return cnt
cnt = 0
dfs(1)
print(cnt)

                