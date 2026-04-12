# -*- coding: utf-8 -*-

def main():

    A, B, C, X, Y = map(int, input().split())

    if A + B <= 2 * C:
        ans = (A * X + B * Y)

    else:
        if X <= Y:
            ans = min(2 * C * X + B * (Y - X), 2 * C * Y)

        else:
            ans = min(2 * C * Y + A * (X - Y), 2 * C * X)
    

    print(ans)


if __name__ == "__main__":
    main()