def solve(A, B, C, X, Y):
    ans = X * A + B * Y
    ans = min(ans, 2 * C * X + B * max(Y - X, 0))
    ans = min(ans, A * max(X - Y, 0) + 2 * C * Y)
    return ans

if __name__ == "__main__":
    A, B, C, X, Y = tuple(map(int, input().split(" ")))
    print(solve(A, B, C, X, Y))
