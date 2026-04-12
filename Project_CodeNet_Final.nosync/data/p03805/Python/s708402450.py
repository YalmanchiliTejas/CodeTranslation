def main():
    import sys

    sys.setrecursionlimit(10 ** 7)

    N, M = map(int, input().split())

    g = tuple(set() for _ in range(N))
    for _ in range(M):
        a, b = (int(x) - 1 for x in input().split())
        g[a].add(b)
        g[b].add(a)

    def dfs(v=0, visited=1 << 0):
        if visited == (1 << N) - 1:
            return 1

        ret = 0
        for u in g[v]:
            if (visited >> u) & 1:
                continue
            ret += dfs(u, visited | (1 << u))
        return ret

    ans = dfs()
    print(ans)


if __name__ == '__main__':
    main()

# import sys
#
# sys.setrecursionlimit(10 ** 7)
#
# input = sys.stdin.readline
# rstrip()
# int(input())
# map(int, input().split())
