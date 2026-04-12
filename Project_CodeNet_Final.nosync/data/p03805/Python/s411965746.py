N, M = map(int, input().split())
ab = [[False]*N for _ in range(N)]

for m in range(M):
    a, b = map(int, input().split())
    ab[a-1][b-1] = True
    ab[b-1][a-1] = True


def solve(n, visit):
    if all(visit):
        return 1
    c = 0
    for i in range(N):
        b = ab[n][i]
        if b and not visit[i]:
            visit[i] = True
            c += solve(i, visit)
            visit[i] = False
    return c


print(solve(0, [True]+[False]*(N-1)))
