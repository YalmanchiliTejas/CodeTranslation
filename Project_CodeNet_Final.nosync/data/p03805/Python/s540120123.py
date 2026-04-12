
N,M = map(int,input().split())

# 無向グラフ
d = [[False] * N
    for _ in range(N)]

for _ in range(M):
    A, B = map(int, input().split())
    d[A - 1][B - 1] = True
    d[B - 1][A - 1] = True

# 訪問したかどうか:スタート頂点の1以外訪問していないとする
visited = [False for _ in range(N)]
visited[0] = True

#Depth first serch
def dfs(v, N, visited):
    if all(visited): #すべて訪問済みなら1を返す
        return 1

    ret = 0
    for i in range(N):
        # 経路存在と訪問済み確認
        if not d[v][i] or visited[i]: #経路がない or 訪問済みなら次
            continue

        visited[i] = True
        
        #再帰
        ret += dfs(i, N, visited)
        
        # 再帰後に元に戻す
        visited[i] = False

    return ret

ans = dfs(0, N, visited)

print(ans)
        
        
        
        
        
        
        