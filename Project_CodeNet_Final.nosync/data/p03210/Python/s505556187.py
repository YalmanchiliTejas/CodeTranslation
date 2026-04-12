#!/usr/bin/env python3
import sys


YES = "YES"  # type: str
NO = "NO"  # type: str


def solve(X: int):
    print(YES if X in {3, 5, 7} else NO)


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
