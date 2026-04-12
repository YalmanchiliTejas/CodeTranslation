from sys import stdin
from itertools import permutations
inf = 10**10
n,m = [int(x) for x in stdin.readline().rstrip().split()]
li = [list(map(int,stdin.readline().rstrip().split())) for _ in range(m)]
lin = [[0 for i in range(n)]for j in range(n)]
for i in li:
    lin[i[0]-1][i[1]-1] = 1
    lin[i[1]-1][i[0]-1] = 1
def all_pairs_shortest_paths(W):
    n = len(W)
    res = [[0] * n for i in range(n)]
    for i in range(n):
        for j in range(i, n):
            if i == j:
                val = 0
            elif W[i][j]:
                val = W[i][j]
            else:
                val = inf
            res[i][j] = res[j][i] = val
    for k in range(n):
        for u in range(n):
            for v in range(n):
                res[u][v] = min(res[u][v], res[u][k] + res[k][v])
    return res
lis = all_pairs_shortest_paths(lin)
liv = [i+1 for i in range(n-1)]
liv = list(permutations(liv))
count = 0
for i in liv:
    keiro = list(i)
    flag = 0
    now = 0
    for j in keiro:
        if lis[now][j] == inf or lis[now][j] != 1:
            flag = 1
        now = j
    if flag == 0:
        count += 1
print(count)