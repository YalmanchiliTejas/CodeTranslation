#!/usr/bin/env python3
import sys
sys.setrecursionlimit(300000)


def solve(c: str):
    if c in 'aeiou':
        ret = 'vowel'
    else:
        ret = 'consonant'
    print(ret)
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
