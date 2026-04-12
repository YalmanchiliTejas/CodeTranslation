import sys
import os


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    S = int(sys.stdin.buffer.readline().decode().replace(' ', ''))
    print('YES' if S%4 == 0 else 'NO')


if __name__ == '__main__':
    main()
