from itertools import permutations

n, m = map(int, input().split())
edge = [[False] * n for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    edge[a-1][b-1] = True
    edge[b-1][a-1] = True

res = 0
for t in permutations(list(range(1, n))):
    l = list(t)
    l.insert(0, 0)
    flag = True

    for i in range(n-1):
        if not edge[l[i]][l[i+1]]:
            flag = False

    if flag:
        res += 1

print(res)