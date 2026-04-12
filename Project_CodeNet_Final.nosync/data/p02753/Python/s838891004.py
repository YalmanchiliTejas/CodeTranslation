import sys


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    s = list(str(readline().rstrip().decode('utf-8')))
    for i in range(1, len(s)):
        if s[i] != s[i-1]:
            print("Yes")
            exit()
    print("No")


if __name__ == '__main__':
    solve()
