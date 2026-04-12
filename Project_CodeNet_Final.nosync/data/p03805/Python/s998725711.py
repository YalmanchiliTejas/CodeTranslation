import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)

ans = 0


def main():
    def dfs(u, visited):
        visited[u] = True
        cnt = 0

        for v in edge[u]:
            if not visited[v]:
                cnt += dfs(v, visited)
                visited[v] = False

        if visited.count(True) == n:
            return 1

        return cnt

    from collections import defaultdict
    n, m = map(int, readline().split())
    edge = defaultdict(list)

    for i in range(m):
        a, b = map(int, readline().split())
        edge[a].append(b)
        edge[b].append(a)

    ans = dfs(1, [False] * (n + 1))
    print(ans)


if __name__ == '__main__':
    main()
