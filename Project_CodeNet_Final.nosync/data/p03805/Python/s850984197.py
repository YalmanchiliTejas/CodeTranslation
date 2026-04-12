N,M=map(int,input().split())
hen = [[False]*N for _ in range(N)]
checked = [False]*N
ans = [0]

def dfs(x):
    if checked[x]==True:
        return
    checked[x]=True
    if checked.count(False)==0:
        ans[0] += 1
        checked[x]=False
        return

    for j in range(0, N):
        if hen[x][j] == True:
            dfs(j)
    checked[x] = False


#島0～N-1
for i in range(M):
    
    a,b=map(int,input().split())
    hen[a-1][b-1] = True
    hen[b-1][a-1] = True

dfs(0)
print(ans[0])