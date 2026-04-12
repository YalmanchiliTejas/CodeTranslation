memo = {}


def solve(N, X):
    if (N, X) not in memo:
        l = (pow(2, N + 2) - 3)
        l2 = (l - 3) // 2 + 1
        if N == 0:
            return 1
        if X == 1:
            return 0
        elif X <= l2:
            memo[(N, X)] = solve(N - 1, X - 1)
        elif X == l2 + 1:
            memo[(N, X)] = solve(N - 1, l2 - 1) + 1
        elif X < l:
            left = solve(N - 1, l2 - 1)
            right = solve(N - 1, X - 1 - l2)
            memo[(N, X)] = left + 1 + right
        elif X == l:
            memo[(N, X)] = solve(N - 1, l2 - 1) * 2 + 1
    return memo[(N, X)]


if __name__ == "__main__":
    N, X = tuple(map(int, input().split(" ")))
    print(solve(N, X))
