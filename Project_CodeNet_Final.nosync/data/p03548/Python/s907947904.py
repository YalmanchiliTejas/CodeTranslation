#!/usr/bin/env python3
import sys
INF = float("inf")


def solve(X: int, Y: int, Z: int):

    N = X // (Y+Z)
    if (Y+Z)*N + Z <= X:
        print(N)
    else:
        print(N-1)
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    X = int(next(tokens))  # type: int
    Y = int(next(tokens))  # type: int
    Z = int(next(tokens))  # type: int
    solve(X, Y, Z)


if __name__ == '__main__':
    main()
