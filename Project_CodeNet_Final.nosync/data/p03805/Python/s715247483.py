def dfs(x, count):
    ret = 0
    if used[x]:
        return ret
    used[x] = 1
    for y in path[x]:
        ret += dfs(y, count + 1)
    used[x] = 0
    if count == N:
        return ret + 1
    else:
        return ret

if __name__ == '__main__':
    N, M = map(int, input().split())
    path = {i + 1: set() for i in range(N)}
    for _ in range(M):
        a, b = map(int, input().split())
        path[a].add(b)
        path[b].add(a)
    used = [0] * (N + 2)
    print(dfs(1, 1))
