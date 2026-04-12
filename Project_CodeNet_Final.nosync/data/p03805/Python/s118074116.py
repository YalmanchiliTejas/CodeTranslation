import itertools
n, m = map(int, input().split())
edge = [[0 for _ in range(n)] for _ in range(n)]
e = [[int(i)-1 for i in input().split()]for _ in range(m)]
for ei in e:
    i, j = ei
    edge[i][j] = 1
    edge[j][i] = 1

paths = itertools.permutations([i for i in range(n)], n)
ok = 0
for path in paths:
    if path[0] != 0:
        continue
    flag = True
    for ei in range(len(path)-1):
        if edge[path[ei]][path[ei+1]] == 0:
            flag = False
        if flag is False:
            break
    if flag:
        ok += 1
print(ok)