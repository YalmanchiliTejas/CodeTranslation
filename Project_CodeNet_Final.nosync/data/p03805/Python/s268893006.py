import sys

# 再帰上限を引き上げる
sys.setrecursionlimit(10**6)

count = 0
def dfs(graph, v, seen):

    if not False in seen:
        global count
        count += 1
        return

    # 頂点vから行ける頂点を全探索
    for i in graph[v]:
        if seen[i]:
            continue
        seen[i] = True
        dfs(graph, i, seen)
        seen[i] = False
    
    return

# ここから本文
N, M = map(int, input().split())

# グラフ構造を作る
graph = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)

seen = [False for i in range(N)]
seen[0] = True
dfs(graph, 0, seen)

print(count)