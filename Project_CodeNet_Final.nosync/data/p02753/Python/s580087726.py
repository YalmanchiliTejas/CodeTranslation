import sys


def solve():
    input = sys.stdin.readline
    mod = 10 ** 9 + 7
    s = str(input().rstrip('\n'))
    if s[0] != s[1] or s[0] != s[2] or s[1] != s[2]:
        print("Yes")
    else:
        print("No")


if __name__ == '__main__':
    solve()
