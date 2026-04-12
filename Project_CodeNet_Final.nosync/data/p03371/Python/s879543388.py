#!/usr/bin/env python3

def main():
    na = list(map(int, input().split()))
    A, B, C, X, Y = na[0], na[1], na[2], na[3], na[4]

    r = 0
    if A + B <= C * 2:
        r = A * X + B * Y
    elif C * 2 < A and C * 2 < B:
        r = C * 2 * max(X, Y)
    elif C * 2 < A:
        r = C * 2 * X
        if X < Y:
            r += B * (Y - X)
    elif C * 2 < B:
        r = C * 2 * Y
        if Y < X:
            r += A * (X - Y)
    else:
        r = C * 2 * min(X, Y)
        if X < Y:
            r += B * (Y - X)
        else:
            r += A * (X - Y)

    print(r)


if __name__ == '__main__':
    main()

