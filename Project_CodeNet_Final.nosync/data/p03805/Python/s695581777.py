import sys
readline = sys.stdin.readline
write = sys.stdout.write

cnt = 0
all_visited = False
def dfs(link, V, i):
    global cnt
    global all_visited
    for j in range(N):
        if V[j] == 0:
            all_visited = False
            break
        all_visited = True
    
    if all_visited == True:
        cnt += 1
        return
    
    adj = len(link[i])
    for j in range(adj):
        if V[link[i][j]] == 0:
            V[link[i][j]] = 1
            dfs(link, V, link[i][j])
            V[link[i][j]] = 0


a = list(map(int,input().split()))
N = a[0]
M = a[1]
link = [[] for i in range(N)]
visited = [0 for i in range(N)]
for i in range(M):
    temp = list(map(int,input().split()))
    link[temp[0]-1].append(temp[1]-1)
    link[temp[1]-1].append(temp[0]-1)
visited[0] = 1
dfs(link, visited, 0)
print(str(cnt))