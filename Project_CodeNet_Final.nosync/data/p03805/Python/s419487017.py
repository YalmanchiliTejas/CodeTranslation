N,M = map(int,input().split())
a = [0]*M
b = [0]*M
for i in range(M):
    a_, b_ = map(int,input().split())
    # 配列の添字としたいので-1
    a[i] = a_ -1
    b[i] = b_ -1

route = [0]*N  # 通過済
connect=[[0]*N for _ in range(N)]
def dfs(now, depth):
    # print("#"*depth,now, depth)
    # 通過済ならNG
    if route[now]: return 0
    # depth = Nなら達成
    if depth == N: return 1
    
    route[now] = 1
    ans = 0
    for i in range(N):
        if connect[now][i]:
            ans += dfs(i, depth+1)
    route[now] = 0
    return ans

for i in range(M):
    connect[a[i]][b[i]] = connect[b[i]][a[i]] = 1

# for xx in connect:
#     print(xx)
print(dfs(0,1))