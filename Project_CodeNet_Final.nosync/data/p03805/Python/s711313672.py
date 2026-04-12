from collections import defaultdict

N,M = map(int,input().split())
edges = [list(map(int,input().split())) for _ in range(M)]
G = defaultdict(list)

is_visited1 = [False] * N

for frm,to in edges:
    G[frm].append(to)
    G[to].append(frm)

def hamilton(node,is_visited,ans):
    #print(is_visited)
    #print(node) 
    is_visited[node-1] =True
    if not False in is_visited:
        ans += 1
        return ans
    for no in G[node]:
        if is_visited[no-1]:
            continue
        ans = hamilton(no,is_visited,ans)
        is_visited[no-1] =False
    #is_visited[node-1] =False        
    return ans
print(hamilton(1,is_visited1,0))
