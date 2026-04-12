import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60


def main():
    A, B, C, X, Y = map(int, readline().split())

    ans = INF
    for k in range(0, 2 * max(X, Y) + 1, 2):
        i = max(0, X - k // 2)
        j = max(0, Y - k // 2)
        if ans > A * i + B * j + C * k:
            ans = A * i + B * j + C * k

    print(ans)
    return


if __name__ == '__main__':
    main()
