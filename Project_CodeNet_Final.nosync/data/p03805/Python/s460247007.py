from itertools import permutations
import sys


sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def main():
    N, M = map(int, input().split())
    perm = list(permutations(range(1, N)))
    edges = [[False] * N for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        edges[a][b] = True
        edges[b][a] = True

    ans = 0
    for P in perm:
        i = 0
        for j in P:
            if edges[i][j]:
                i = j
            else:
                break
        else:
            ans += 1

    print(ans)


if __name__ == "__main__":
    main()
