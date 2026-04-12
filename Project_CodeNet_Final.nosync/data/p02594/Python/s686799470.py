import sys


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    x = int(readline())
    print("Yes" if x >= 30 else "No")


if __name__ == '__main__':
    solve()
