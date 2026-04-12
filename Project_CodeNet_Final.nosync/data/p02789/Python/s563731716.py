import sys
import os

MOD = 10 ** 9 + 7


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    N, M = list(map(int, sys.stdin.buffer.readline().split()))
    print('Yes' if N == M else 'No')


if __name__ == '__main__':
    main()
