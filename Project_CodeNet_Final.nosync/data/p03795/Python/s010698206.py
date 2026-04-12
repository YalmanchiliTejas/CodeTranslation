#!/usr/bin/env python3
import sys
sys.setrecursionlimit(300000)


def solve(N: int):
    ret = 800 * N - (N // 15) * 200
    print(ret)
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
