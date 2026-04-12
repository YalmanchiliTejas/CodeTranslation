import sys
from collections import defaultdict

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def main():

    N, M = map(int, input().split())
    G = defaultdict(lambda: [])

    for i in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        G[a].append(b)
        G[b].append(a)

    # print(G)

    def dfs(v, is_visited):
        if sum(is_visited) == N:
            return 1
        ans = 0
        for u in G[v]:
            if is_visited[u]:
                continue
            is_visited[u] = True
            ans += dfs(u, is_visited)
            is_visited[u] = False

        return ans

    is_visited = [False] * N
    is_visited[0] = True

    print(dfs(0, is_visited))


if __name__ == "__main__":
    main()
