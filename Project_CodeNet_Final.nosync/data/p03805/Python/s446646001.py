N, M = map(int, input().split())

path_matrix = []

#無向行列の初期化
for n in range(N):
    path_matrix.append([False] * N)

#まず無向グラフを表す行列を作る
for m in range(M):
    a,b = map(int, input().split())
    path_matrix[a-1][b-1] = True
    path_matrix[b-1][a-1] = True
#無向グラフを表す行列はpath_matrix[i][j]iの部分が各頂点でjが他の頂点との繋がりを意味する
#最初はvisited、つまり訪問したことのあるノードはひとつもないので、Falseにする
visited = [False] * N #この問題は各頂点をすべて通る方法を調べること
def dfs(now,depth):
    if visited[now]:#もし現在位置が訪問済みなら
        return 0
    if depth == N-1:#もし深さが最大までいったらすべての頂点を探索し終えたので１を返す
        return 1
    
    visited[now] = True#現在位置を訪問済みにする(これをしないとループし続ける)
    total_path = 0
    for i in range(N):
        if path_matrix[now][i]:#もし飛べる先があるのなら、その飛んだ先のノードで今いる位置と深さを更新した上で、もっと掘り下げてみる
            total_path += dfs(i,depth+1)#もし深さが最大まで行ったらすべての頂点について探索が終了したので1加える

    visited[now] = False

    return total_path


print(dfs(0,0))