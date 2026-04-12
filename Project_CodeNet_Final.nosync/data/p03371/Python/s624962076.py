def main():
    A, B, C, X, Y = map(int, input().split())

    if X <= Y:
        print(min((Y - X) * B + C * 2 * X, 2 * C * Y, A * X + B * Y))
    else:
        print(min((X - Y) * A + C * 2 * Y, 2 * C * X, A * X + B * Y))



main()