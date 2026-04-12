N, M = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(M)]

# グラフ組み立て
g = [["#" for _ in range(N)] for _ in range(N)]
for p in ab:
    g[p[0]-1][p[1]-1] = "-"
    g[p[1]-1][p[0]-1] = "-"

import itertools

# 頂点集合
n = [i for i in range(N)]

# 全ての組み合わせを調べる
ans = 0
for p in itertools.permutations(n, len(n)):
    flag = 1
    if p[0] != 0: # 頂点が合わない場合
        continue
    for i in range(N-1):
        if g[p[i]][p[i+1]] != "-":
            flag = 0
            break
    if flag:
        ans += 1
print(ans)
    