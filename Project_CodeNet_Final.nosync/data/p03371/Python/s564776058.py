from sys import stdin


def main():
    A, B, C, X, Y = [int(x) for x in stdin.readline().rstrip().split()]
    if A + B <= C * 2:
        print(A * X + B * Y)
    elif X < Y:
        spam = C * 2 * X
        if B < C * 2:
            print(B * (Y - X) + spam)
        else:
            print(C * 2 * (Y - X) + spam)
    else:
        spam = C * 2 * Y
        if A < C * 2:
            print(A * (X - Y) + spam)
        else:
            print(C * 2 * (X - Y) + spam)


if __name__ == '__main__':
    main()
