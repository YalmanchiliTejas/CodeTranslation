from itertools import permutations

N, M = map(int, input().split())
root = [[0] * N for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    root[a-1][b-1] = 1
    root[b-1][a-1] = 1

ans = 0
for r in permutations(range(N)):
    if r[0] != 0: break
    factor = 1
    for i in range(len(r)-1):
        factor *= root[r[i]][r[i+1]]
    ans += factor
print(ans)
