def main():
    A, B, C, X, Y = list(map(int, input().split(' ')))
    p1 = A * X + B * Y
    p2 = 2 * C * X + B * max([0, Y - X])
    p3 = 2 * C * Y + A * max([0, X - Y])
    p4 = 2 * C * max([X, Y])
    print(min([p1, p2, p3, p4]))


if __name__ == '__main__':
    main()