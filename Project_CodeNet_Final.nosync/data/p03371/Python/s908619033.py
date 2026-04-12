def main():
    A, B, C, X, Y = map(int, input().split())
    print(
        min(A * X + B * Y,
            2 * C * max(X, Y),
            2 * C * min(X, Y) + (B if X < Y else A) * abs(X - Y)))
    return


main()
