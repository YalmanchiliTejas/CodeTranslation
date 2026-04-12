n,m=map(int,input().split())
path=[[0]*n for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    path[a-1][b-1]=1
    path[b-1][a-1]=1#隣接グラフを作成
visited=[0]*n#どこを通ったか記憶
visited[0]=1#１は最初に通る
def dfs(position,visited,n):#深さ優先探索
    all_visited=1
    for i in range(n):
        if visited[i]==0:
            all_visited=0#行ったことがない点があれば０
            break#どこかで見つかったらループ終了
    if all_visited==1:
        return 1#全部回れたら１回カウント
    count=0#経路の個数をカウント
    for next in range(n):#次に移動する点
        if path[position][next]==0:
            continue#道がなければ次へ
        if visited[next]==1:
            continue#行ったことがあれば次へ
        visited[next]=1
        count+=dfs(next,visited,n)
        visited[i]=0#行った記録を消去して前のループに戻る
    visited[position]=0

    return count
print(dfs(0,visited,n))
