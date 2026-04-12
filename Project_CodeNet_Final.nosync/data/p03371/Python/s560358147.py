import sys

sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def main():
    A, B, C, X, Y = map(int, input().split())
    M = max(X, Y)
    ans = INF
    for i in range(0, 2 * M + 1, 2):
        tmp = i * C
        rest_a = max(X - i // 2, 0)
        rest_b = max(Y - i // 2, 0)
        tmp += rest_a * A + rest_b * B
        if tmp < ans:
            ans = tmp

    print(ans)


if __name__ == "__main__":
    main()
