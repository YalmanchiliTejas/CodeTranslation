from copy import deepcopy

cnt = 0
depth = 0


def main():
    n, m = map(int, input().split())
    adj = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        adj[a].append(b)
        adj[b].append(a)

    def f(u, d):
        global cnt, depth
        cp = deepcopy(d)
        cp[u] = depth
        if cp.count(-1) == 0:
            cnt += 1
        else:
            vs = adj[u]
            depth += 1
            for v in vs:
                if cp[v] == -1:
                    f(v, cp)
            depth -= 1

    f(0, [-1] * n)

    print(cnt)


if __name__ == "__main__":
    main()
