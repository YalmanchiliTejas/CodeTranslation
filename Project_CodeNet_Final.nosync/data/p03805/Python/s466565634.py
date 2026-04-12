import sys
# 再帰上限を引き上げる
sys.setrecursionlimit(10**6)

####
# DFS(深さ優先探索

count = 0
def dfs(graph, v, seen):
    #print(seen)
    # Falseがない、つまり頂点が1個しかない場合は、1を返す
    if not False in seen:
        global count
        count += 1
        return
    
    # 頂点Vから行ける頂点を全探索
    for i in graph[v]:
        # 行ける場所はTrueである。
        if seen[i]:
            continue
        
        # いったんTrueにして
        seen[i] = True
        # 探索したら
        dfs(graph, i, seen)
        # 戻す
        seen[i] = False
        
    return
        
        

####

N, M = map(int, input().split())

# グラフを作る
graph = [[] for i in range(N)]
#print(graph)

for i in range(M):
    a, b = map(int, input().split())
    # index番号にあわせたいので、1引く
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)
    
seen = [False for i in range(N)]
seen[0] = True
dfs(graph, 0, seen)

# 全探索できた数を表示
print(count)