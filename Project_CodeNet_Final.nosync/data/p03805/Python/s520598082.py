import itertools

N, M = map(int, input().split())
ab = list(list(map(int,input().split())) for _ in range(M))

# 辺が存在する箇所にフラグ1を置く
edge = [[0 for _ in range(N)] for _ in range(N)]
for idx in range(M):
    edge[ab[idx][0]-1][ab[idx][1]-1] = 1
    edge[ab[idx][1]-1][ab[idx][0]-1] = 1


# 頂点1から始まる全通りのパスについて実現可能かを調べる
path = list(range(2,N+1))
path = list(itertools.permutations(path))
ans = 0

for out_idx in range(len(path)):
    path[out_idx] = (1,) + path[out_idx]
    miss_flg = 0
    for in_idx in range(1, len(path[out_idx])-1):
        if edge[path[out_idx][in_idx-1]-1][path[out_idx][in_idx]-1] == 0 or edge[path[out_idx][in_idx]-1][path[out_idx][in_idx+1]-1] == 0:
            miss_flg = 1
            break
    if miss_flg == 0:
        ans += 1

print(ans)