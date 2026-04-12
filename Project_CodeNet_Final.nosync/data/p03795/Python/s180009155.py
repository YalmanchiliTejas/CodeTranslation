import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N = int(readline())
    x = N * 800
    y = (N // 15) * 200
    print(x - y)
    return


if __name__ == '__main__':
    main()
