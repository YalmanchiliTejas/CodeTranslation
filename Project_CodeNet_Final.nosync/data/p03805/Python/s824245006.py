N, M = map(int, input().split())
to = [[] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    to[a].append(b)
    to[b].append(a)


res = 0
def dfs(v, seen):
    global res
    if seen == [1] * N:
        res += 1
        return
    for nv in to[v]:
        if not seen[nv]:
            seen[nv] = 1
            dfs(nv, seen)
            seen[nv] = 0


def main():
    seen = [0] * N
    seen[0] = 1
    dfs(0, seen)
    print(res)


if __name__ == "__main__":
    main()
