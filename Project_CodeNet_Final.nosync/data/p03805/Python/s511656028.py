import itertools

n, m = map(int, input().split())
path = [[False for _ in range(n)] for __ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    path[a-1][b-1] = True
    path[b-1][a-1] = True
example = [i for i in range(1, n)]

ans = 0
for ex in itertools.permutations(example):
    e = [0] + list(ex)
    for a, b in zip(e, e[1:]):
        if path[a][b] is False:
            break
    else:
        # print(e)
        ans += 1
print(ans)