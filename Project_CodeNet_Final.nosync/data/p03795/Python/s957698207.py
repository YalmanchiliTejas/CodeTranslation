import sys
import os


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    N = int(sys.stdin.readline().rstrip())
    m = N // 15
    print(N * 800 - m * 200)


if __name__ == '__main__':
    main()
