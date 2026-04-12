import sys


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    s = str(readline().rstrip().decode('utf-8'))
    for i in range(len(s)-1):
        if s[i:i+2] == "AC":
            print("Yes")
            exit()
    print("No")


if __name__ == '__main__':
    solve()
