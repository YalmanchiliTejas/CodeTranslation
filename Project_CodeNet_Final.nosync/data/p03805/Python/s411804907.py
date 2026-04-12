N, M = map(int, input().split())

ans = 0

# 隣接リストの作成
vertex_list = [[] for i in range(N+1)]
for i in range(M):
    a, b = map(int, input().split())
    vertex_list[a].append(b)
    vertex_list[b].append(a)

def dfs(v):
    global ans, used
    if len(used) == N:
        ans += 1
        return
    else:
        for next_v in vertex_list[v]:
            if next_v not in used:
                used.add(next_v)
                dfs(next_v)
                used.remove(next_v)
        return

used = set([1])
dfs(1)

print(ans)