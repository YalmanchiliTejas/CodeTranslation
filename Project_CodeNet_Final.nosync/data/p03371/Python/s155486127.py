if __name__ == '__main__':
    A, B, C, X, Y = list(map(int, input().split()))
    if A + B <= 2 * C:
        # print(1)
        print(A * X + B * Y)
    else:
        if X == Y:
            # print(2)
            print(C * 2 * X)
        elif X < Y:
            # print(3)
            print(min(X * C * 2 + B * (Y - X), C * 2 * Y))
        else:
            # print(4)
            print(min(Y * C * 2 + A * (X - Y), C * 2 * X))
