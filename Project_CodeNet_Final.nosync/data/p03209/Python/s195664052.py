#!/usr/bin/env python3

def calc(N, X):
    if X == 0:
        return 0
    elif X == 2 ** (N + 2) - 3:
        return 2 ** (N + 1) - 1

    Y = 2 ** (N + 1) - 1
    if X == Y:
        return 2 ** N
    elif X == Y - 1:
        return 2 ** N - 1
    elif X < Y - 1:
        return calc(N - 1, X - 1)
    else:
        return 2 ** (N + 1) - 1 - calc(N - 1, 2 ** (N + 2) - 4 - X)

def main():
    [N, X] = list(map(int, input().split()))

    r = calc(N, X)


    print(r)


if __name__ == '__main__':
    main()

