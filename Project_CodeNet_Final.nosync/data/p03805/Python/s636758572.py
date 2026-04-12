import itertools

N, M = map(int, input().split())

graph = [[False]*N for _ in range(N)]

for _ in range(M):
    a, b = map(lambda x: int(x)-1, input().split())
    graph[a][b] = True
    graph[b][a] = True

ans = 0

#頂点を並び替える順列を生成してループ
for path in itertools.permutations(range(N), N):
    if path[0] == 0: #先頭が頂点1の時
        for i in range(N):
            if i==N-1:
                ans += 1
                break
            if not graph[path[i]][path[i+1]]:
                break
print(ans)
