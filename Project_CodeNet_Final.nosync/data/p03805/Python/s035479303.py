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
    G = [[False] * N for _ in range(N)]
    for a, b in zip(*[iter(AB)] * 2):
        G[a - 1][b - 1] = G[b - 1][a - 1] = True

    ans = 0
    for perm in permutations(range(1, N)):
        if not G[0][perm[0]]:
            continue
        ok = True
        for i in range(N - 2):
            if not G[perm[i]][perm[i + 1]]:
                ok = False
                break
        if ok:
            ans += 1

    print(ans)
    return


if __name__ == '__main__':
    main()
