import sys
import collections

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]

    A.sort()

    if N % 2 == 0:
        ans = sum(A[N // 2:]) * 2 - A[N // 2] - sum(A[:N // 2]) * 2 + A[N // 2 - 1]
    else:
        ans = sum(A[N // 2:]) * 2 - A[N // 2] - A[N // 2 + 1] - sum(A[:N // 2]) * 2
        ans = max(ans, sum(A[N // 2 + 1:]) * 2 - sum(A[:N // 2 + 1]) * 2 + A[N // 2] + A[N // 2 - 1])
    print(ans)


if __name__ == '__main__':
    main()
