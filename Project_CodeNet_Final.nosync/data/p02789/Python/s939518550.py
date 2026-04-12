#!/usr/bin/env python3
import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines


def main():
    N, M = map(int, readline().split())
    if N == M:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()
