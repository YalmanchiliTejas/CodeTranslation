#!/usr/bin/env python3
import sys
INF = float("inf")


def solve(N: int):
    x = N*800
    y = (N//15) * 200
    print(x-y)
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    solve(N)


if __name__ == '__main__':
    main()
