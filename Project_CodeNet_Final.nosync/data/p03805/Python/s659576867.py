n,m=map(int,input().split())
def dfs(now,depth):#現在見ている点、今まで列挙した頂点数
    if used[now]:
        return 0
    if depth==n:
        return 1
    used[now]=1#使用済みグラフを立てる
    ans=0#出力値を数える変数
    for i in range(n):#全部の遷移先を調べる
        if connect[now][i]:#nowから繋がっている頂点であれば遷移を試す。
            ans+=dfs(i,depth+1)
    used[now]=0#使用済みグラフを折る
    return ans
edge=[[int(i)for i in input().split()]for i in range(m)]#入力値受け取り、グラフの初期設定
connect=[[0 for i in range(n)]for i in range(n)]#接続状況を管理する配列
for i in range(m):
    connect[edge[i][0]-1][edge[i][1]-1]=1
    connect[edge[i][1]-1][edge[i][0]-1]=1
used=[0]*n#既にその頂点を訪問したか管理する配列
print(dfs(0,1))
