from itertools import permutations
n_ver,n_edge = map(int,input().split())
path_mat = [[0]*n_ver for _ in range(n_ver)]
for i in range(n_edge):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    path_mat[a][b] = 1
    path_mat[b][a] = 1
ans = 0
vers = [i for i in range(n_ver)]
for path in permutations(vers):
    if path[0] != 0:
        continue
    can = True
    for i in range(n_ver-1):
        from_ = path[i]
        to = path[i+1]
        if not path_mat[from_][to]:
            can = False
            break
    if can:
        ans += 1
print(ans)

