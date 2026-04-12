import sys
import os

ii = lambda: int(sys.stdin.buffer.readline().rstrip())
il = lambda: list(map(int, sys.stdin.buffer.readline().split()))

iss = lambda: sys.stdin.buffer.readline().decode().rstrip()
isn = lambda n: [sys.stdin.buffer.readline().decode().rstrip() for _ in range(n)]


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    N = iss()
    print('YES' if N in '753' else 'NO')



if __name__ == '__main__':
    main()
