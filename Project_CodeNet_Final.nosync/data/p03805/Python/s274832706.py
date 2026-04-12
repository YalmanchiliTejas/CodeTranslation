def dfs(v,n,visited):
    all_visted=1#全ての点を探索したか判別する
    for i in range(n):
        if visited[i]==0:#まだi番目の点を訪問していない時
            all_visted=0
    if all_visted==1:#全ての辺を訪問した場合
        return 1
    count=0#全ての辺を訪問する回数を格納する変数
    for i in range(n):
        if path[v][i]==0:#辺がないとき、つまり隣接していない時
            continue
        if visited[i]==1:#既に訪問している
            continue
        visited[i]=1#訪問する
        count+=dfs(i,n,visited)#countに+1をする
        visited[i]=0#まだ探索していないノードまで戻る
    return count
#グラフの位置情報を読み取る
n,m=map(int,input().split())
path=[[0]*n for i in range(n)]#0は未訪問,1は訪問済み
for i in range(m):
    a,b=map(int,input().split())
    path[a-1][b-1]=1#隣接しているところは1になる
    path[b-1][a-1]=1
visited=[0]*n
visited[0]=1#点1は既に訪問済みなので記録
print(dfs(0,n,visited))
