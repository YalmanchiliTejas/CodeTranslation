import sys


def solve():
    input = sys.stdin.readline
    mod = 10 ** 9 + 7
    n, m = list(map(int, input().rstrip('\n').split()))
    if n == m:
        print("Yes")
    else:
        print("No")


if __name__ == '__main__':
    solve()
