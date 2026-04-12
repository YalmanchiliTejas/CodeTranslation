from collections import defaultdict

def dfs(res, depth, path, adj_list, visited):
    if path in visited:
        return
    elif depth == 1:
        res[0]+=1
        return
    for node in adj_list[path]:
        dfs(res, depth-1, node, adj_list, visited+[path])  

N, M = map(int, input().split())
adj_list = defaultdict(list)
for i in range(M):
    a, b = map(int, input().split())
    adj_list[a].append(b)
    adj_list[b].append(a)

res = [0]
for node in adj_list[1]:
    dfs(res, N-1, node, adj_list, [1])
print(res[0])
