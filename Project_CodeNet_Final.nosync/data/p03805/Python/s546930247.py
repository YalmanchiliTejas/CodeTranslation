import sys
from itertools import permutations

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N, M, *AB = map(int, read().split())
    G = [[] for _ in range(N)]
    for a, b in zip(*[iter(AB)] * 2):
        G[a - 1].append(b - 1)
        G[b - 1].append(a - 1)

    def dfs(v, seen):
        if len(seen) == N:
            return 1

        ans = 0
        for nv in G[v]:
            if nv not in seen:
                seen.add(nv)
                ans += dfs(nv, seen)
                seen.remove(nv)

        return ans

    print(dfs(0, {0}))
    return


if __name__ == '__main__':
    main()
