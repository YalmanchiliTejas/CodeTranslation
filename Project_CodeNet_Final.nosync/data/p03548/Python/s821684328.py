#!/usr/bin/env python3
import sys


def solve(X: int, Y: int, Z: int):
    print((X - Z) // (Y + Z))


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
