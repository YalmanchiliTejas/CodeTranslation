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

    G = [row for row in G if row != '.' * W]
    G = list(''.join(row) for row in zip(*G))
    G = [row for row in G if row != '.' * len(row)]
    G = list(''.join(row) for row in zip(*G))

    print(*G, sep='\n')

    return


if __name__ == '__main__':
    main()
