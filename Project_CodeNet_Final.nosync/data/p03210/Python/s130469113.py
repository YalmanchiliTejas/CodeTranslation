#!/usr/bin/env python3
import sys
INF = float("inf")


def yes():
    print("YES")  # type: str


def no():
    print("NO")  # type: str


def solve(X: int):
    if X == 3 or X == 5 or X == 7:
        yes()
    else:
        no()
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    X = int(next(tokens))  # type: int
    solve(X)


if __name__ == '__main__':
    main()
