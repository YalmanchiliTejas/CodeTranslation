def dfs(t):
    # 全ての辺を訪問していた場合
    if (0 not in already): return 1
    # 全ての辺を訪問する回数を格納する変数
    allReach=0
    for i in range(N):
        # 辺があり、訪問していない場合
        if connect[t][i]==1 and already[i]==0:
            already[i]=1
            allReach+=dfs(i)
            already[i]=0
    return allReach


N,M=map(int,input().split())

connect=[[0for i in range(N)]for j in range(N)]
for i in range(M):
    a,b=map(int, input().split())
    # 辺の情報を記録する
    connect[a-1][b-1]=1
    connect[b-1][a-1]=1

# 訪問した頂点を記録する
already=[0 for i in range(N)]
# 必ず1から始まるので訪問履歴をつけておく
already[0]=1
# 記録した情報をもとに0からdfs
print(dfs(0))
