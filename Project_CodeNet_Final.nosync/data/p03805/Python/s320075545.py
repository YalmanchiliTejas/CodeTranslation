# 深さ優先探索
def dfs(V, closed): # V:探索頂点, closed:探索済み頂点リスト
 
    # 全頂点を探索したとき
    if not False in closed:
        return 1
    
    answer = 0
    for i in range(N):
        if not graph[V][i]:
            continue
        if closed[i]:
            continue
 
        # 頂点iを探索済みにする
        closed[i] = True
        answer += dfs(i,closed)
 
        # 最深まで探索したとき
        closed[i] = False
    
    return answer
 
N,M = map(int,input().split())
graph = [[False for i in range(N)] for j in range(N)]
 
for i in range(M):
    a,b = map(int,input().split())
    graph[a-1][b-1] = graph[b-1][a-1] = True
 
closed_list = [False]*N
closed_list[0] = True
 
print(dfs(0,closed_list))