import sys

sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    A.sort()

    if N % 2 == 0:
        ans = A[N // 2] - A[N // 2 - 1]
        for i in range(N // 2 - 1):
            ans -= 2 * A[i]
        for i in range(N // 2 + 1, N):
            ans += 2 * A[i]
    else:
        ans1 = -A[N // 2] - A[N // 2 - 1]
        for i in range(N // 2 - 1):
            ans1 -= 2 * A[i]
        for i in range(N // 2 + 1, N):
            ans1 += 2 * A[i]

        ans2 = A[N // 2] + A[N // 2 + 1]
        for i in range(N // 2):
            ans2 -= 2 * A[i]
        for i in range(N // 2 + 2, N):
            ans2 += 2 * A[i]

        ans = max(ans1, ans2)

    print(ans)


if __name__ == "__main__":
    main()
