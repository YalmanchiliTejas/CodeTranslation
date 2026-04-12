import sys


def input():
    return sys.stdin.readline().strip()


sys.setrecursionlimit(10 ** 9)


def main():
    A, B, C, X, Y = map(int, input().split())
    money = []
    money.append(X * A + Y * B)
    if X > Y:
        money.append(X * 2 * C)
        money.append(Y * 2 * C + (X - Y) * A)
    elif X == Y:
        money.append(X * 2 * C)
    else:
        money.append(Y * 2 * C)
        money.append(X * 2 * C + (Y - X) * B)
    print(min(money))


if __name__ == "__main__":
    main()
