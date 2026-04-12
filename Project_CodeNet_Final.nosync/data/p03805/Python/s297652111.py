from sys import stdin


def dfs(g, seen, n):
    all_seen = True

    for si in seen:
        if si == False:
            all_seen = False

    if all_seen:
        return 1

    ans = 0

    for m in g[n]:
        if seen[m]:
            continue

        seen[m] = True
        ans += dfs(g, seen, m)
        seen[m] = False

    return ans


def main():
    n, m = map(int, stdin.readline().split())
    ab = [map(int, stdin.readline().split()) for _ in range(m)]
    g = [[] for _ in range(n)]
    for abi in ab:
        a, b = abi
        g[a - 1].append(b - 1)
        g[b - 1].append(a - 1)
    seen = [False for _ in range(n)]
    seen[0] = True

    ans = dfs(g, seen, 0)

    print(ans)


if __name__ == "__main__":
    main()
