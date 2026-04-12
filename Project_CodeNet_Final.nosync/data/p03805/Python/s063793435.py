from itertools import permutations

N, M = [int(i) for i in input().split()]
adjacent = [[0] * N for _ in range(N)]
for _ in range(M):
    a, b = [int(i) for i in input().split()]
    adjacent[a - 1][b - 1] = 1
    adjacent[b - 1][a - 1] = 1

ans = 0
for p in permutations(range(N), r=N):
    if p[0] != 0:
        continue
    for i in range(1, N):
        f, t = p[i-1:i+1]
        if adjacent[f][t] != 1:
            break
    else:
        ans += 1
print(ans)
