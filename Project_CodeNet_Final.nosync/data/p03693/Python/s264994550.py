import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    r, g, b = map(int, read().split())

    n = 100 * r + 10 * g + b
    if n % 4 == 0:
        print('YES')
    else:
        print('NO')

    return


if __name__ == '__main__':
    main()
