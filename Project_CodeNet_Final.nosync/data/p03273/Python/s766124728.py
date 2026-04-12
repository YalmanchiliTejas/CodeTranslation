import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    H, W = map(int, readline().split())
    G = [readline().strip() for _ in range(H)]

    row = [False] * H
    col = [False] * W

    for i in range(H):
        for j in range(W):
            if G[i][j] == '#':
                row[i] = col[j] = True

    for i in range(H):
        if not row[i]:
            continue
        for j in range(W):
            if col[j]:
                print(G[i][j], end='')
        print('')

    return


if __name__ == '__main__':
    main()
