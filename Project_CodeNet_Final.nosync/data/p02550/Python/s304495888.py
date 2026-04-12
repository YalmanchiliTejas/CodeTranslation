import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N, X, M = map(int, readline().split())

    P = N.bit_length()
    pos = [[0] * M for _ in range(P)]
    value = [[0] * M for _ in range(P)]

    for r in range(M):
        pos[0][r] = r * r % M
        value[0][r] = r

    for p in range(P - 1):
        for r in range(M):
            pos[p + 1][r] = pos[p][pos[p][r]]
            value[p + 1][r] = value[p][r] + value[p][pos[p][r]]

    ans = 0
    cur = X
    for p in range(P):
        if N & (1 << p):
            ans += value[p][cur]
            cur = pos[p][cur]

    print(ans)
    return


if __name__ == '__main__':
    main()
