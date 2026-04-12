#!/usr/bin/env python3
import sys
INF = float("inf")


def solve(c: str):
    if c in ["a", "e", "i", "o", "u"]:
        print("vowel")
    else:
        print("consonant")
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    c = next(tokens)  # type: str
    solve(c)


if __name__ == '__main__':
    main()
