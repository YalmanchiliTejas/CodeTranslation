N, X = map(int, input().split())
if X <= N:
    print(0)
    exit(0)
p = [0]*(N+1)
p[0] = 1
for i in range(1, N+1):
    p[i] = p[i-1]*2 + 3


def solve(N, X):
    ret = 0
    if X == p[N]:
        return((p[N]+1) // 2)
    elif X <= N:
        return(0)
    else:
        if X >= (p[N] + 1) // 2:
            ret += ((p[N-1]+1) // 2) + 1
            X = X - (p[N-1] + 1)
        ret += solve(N-1, X-1)
        return(ret)


print(solve(N, X))
