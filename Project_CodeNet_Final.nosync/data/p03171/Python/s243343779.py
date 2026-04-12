import sys
from collections import deque


def input():
    return sys.stdin.readline().rstrip()


def main():
    N = int(input())
    A = list(map(int, input().split()))

    dp = [[0] * (N + 1) for _ in range(N + 1)]

    for i in range(N):
        dp[i][i] = A[i]

    for k in range(1, N):  # distance
        for i in range(N):  # start grid
            if i + k >= N:
                break
            dp[i][i + k] = max(A[i + k] - dp[i][i + k - 1], A[i] - dp[i + 1][i + k])

    print(dp[0][N-1])


if __name__ == "__main__":
    main()
