def dfs(t):
    if 0 not in already:#全ての辺を訪問していた場合
        return 1
    allReach=0
    for i in range(n):
        if connect[t][i]==1 and already[i]==0:#辺があり、訪問しいない場合
            already[i]=1
            allReach+=dfs(i)
            already[i]=0
    return allReach

n,m=map(int,input().split())
connect=[[0 for i in range(n)]for j in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    #辺の情報を記録する
    connect[a-1][b-1]=1
    connect[b-1][a-1]=1
already=[0 for i in range(n)]#訪問した点を記録する
already[0]=1#必ず1から始まるので訪問履歴をつけておく
print(dfs(0))#記録した情報をもとに0からdfs
