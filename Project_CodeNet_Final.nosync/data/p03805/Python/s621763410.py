nmax=8
#深さ優先探索
def dfs(v,n,visited):
    all_visited=True
    for i in range(n):
        #ある経路においてvisitedすべてTrueか
        if visited[i]==False:
            all_visited=False
    if all_visited:
        return 1
    
    ans=0
    for i in range(n):
        #パスがないならcontinue
        if graph[v][i]==False:
            continue
        #すでに通ったならcontinue
        if visited[i]:
            continue
        #通った頂点をTrueにする
        visited[i]=True
        #次の深さを探索
        ans += dfs(i,n,visited)
        #深いところから戻るのでvisitedをFalseに
        visited[i]=False
    return ans

n,m = map(int,input().split())
#graph[n][n]をFalseで初期化
graph=[]
for i in range(n):
    graph.append([False]*n)
#graph上でパスの通っているものをTrueとする
for _ in range(m):
    a,b = map(int,input().split())
    graph[a-1][b-1]=True
    graph[b-1][a-1]=True
#visited[n]をFalseで初期化
visited=[]
for _ in range(n):
    visited.append(False)
#頂点1を始点とする(visited[(頂点)-1])
visited[0]=True
print(dfs(0,n,visited))