import itertools


N, M = map(int, input().split())
graph = [[False]*N for _ in range(N)]

for _ in range(M):
    a, b = map(lambda x: int(x)-1, input().split())
    graph[a][b] = True
    graph[b][a] = True

ans = 0
for x in itertools.permutations(range(1, N)):
    # このxの順番で訪問できるか確かめる
    flag = True
    now = 0
    for e in x:
        if not graph[now][e]:
            flag = False
        now = e
    if flag:
        ans += 1
print(ans)
