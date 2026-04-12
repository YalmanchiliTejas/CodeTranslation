from math import ceil, floor

# dp[a_i番まで見た。a_iを含む][a_i（を含む）までにいくつ採用しているか][i - 1を使ったかどうか] bool
memo = {}


def dp(i, j):
    if (i, j) in memo:
        return memo[(i, j)]
    else:
        return float("inf")*-1


def main():
    n = int(input())
    A = [0] + list(map(int, input().split()))
    memo[(0, 0)] = 0
    memo[(1, 1)] = A[1]
    memo[(1, 0)] = 0
    for i in range(2, n + 1):
        for j in range(max(floor(n/2) - ceil((n-i)/2) - 1, 0), floor(i/2) + 5):
            # a_iを採用する場合
            if (i, j) in memo:
                memo[(i, j)] = max(
                    [dp(i, j), A[i] + dp(i - 2, j - 1), A[i] + dp(i - 3, j - 1)])
            else:
                memo[(i, j)] = max(A[i] + dp(i - 2, j - 1),
                                   A[i] + dp(i - 3, j - 1))
            # a_iを採用しない場合
            if (i - 1, j) in memo:
                memo[(i, j)] = max(dp(i - 1, j), dp(i, j))

    print(dp(n, floor(n/2)))
    return
if __name__ == "__main__":
    main()
