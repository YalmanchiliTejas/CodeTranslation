import sys
input = sys.stdin.readline


if __name__ == '__main__':

    N = int(input())
    A = list(map(int, input().split()))

    dp = [0] * N
    dp[1] = max(A[0], A[1])
    c = A[0]

    for i in range(2, N):
        if i % 2 == 0:
            dp[i] = max(dp[i - 2] + A[i], dp[i - 1])
            c += A[i]
        else:
            dp[i] = max(dp[i - 2] + A[i], c)

    print(dp[-1])
