import sys


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    n, m = list(map(int, readline().split()))
    print("Yes" if n == m else "No")


if __name__ == '__main__':
    solve()
