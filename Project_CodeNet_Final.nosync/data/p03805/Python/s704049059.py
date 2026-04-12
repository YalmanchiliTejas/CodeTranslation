from itertools import permutations

N, M = map(int, input().split())
path = [[0 for _ in range(N)] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    path[a-1][b-1] = 1
    path[b-1][a-1] = 1

all_routes = list(permutations([i for i in range(1, N + 1)]))

ans = 0
for route in all_routes:
    flg = True
    if route[0] != 1:
        break
    for i in range(1, N):
        if path[route[i-1] - 1][route[i] - 1] != 1:
            flg = False
            break
    if flg:
        ans += 1

print(ans)
