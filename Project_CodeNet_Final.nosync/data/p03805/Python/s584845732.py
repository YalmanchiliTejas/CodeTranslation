N,M = map(int,input().split())
pat = [[int(i) for i in input().split()] for _ in range(M)]
Graph = [[0 for i in range(N)] for _ in range(N)]
for i,j in pat:
    Graph[i-1][j-1] = 1
    Graph[j-1][i-1] = 1

def dfs(v,N,visit_list):

    all_visit = True

    for i in range(N):
        if visit_list[i] == False:
            all_visit = False
    
    if all_visit:
        return 1

    ret = 0

    for k in range(N):
        if Graph[v][k] == False:
            continue
        if visit_list[k] :
            continue
        
        visit_list[k] = True
        ret += dfs(k,N,visit_list)
        visit_list[k] = False
    return ret

visit_list = [False for i in range(N)]
visit_list[0] = True
print(dfs(0,N,visit_list))
    

