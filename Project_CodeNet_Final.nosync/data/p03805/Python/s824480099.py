n, m = map(int, input().split())
edge = [tuple(map(int, input().split())) for _ in range(m)]

connect = [[0 for _ in range(n)] for _ in range(n)]
for a, b in edge:
    connect[a-1][b-1] = 1
    connect[b-1][a-1] = 1

import itertools
ans = 0
for l in itertools.permutations(range(1, n)):
    ok = True
    pre = 0
    for x in l:
        if connect[pre][x] == 0:
            ok = False
            break
        pre = x
    if ok:
        ans += 1
print(ans)