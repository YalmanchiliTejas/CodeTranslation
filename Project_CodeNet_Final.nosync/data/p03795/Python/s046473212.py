import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    N = int(readline())

    print(N * 800 - N // 15 * 200)


if __name__ == '__main__':
    main()
