import sys

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    x = int(input())
    print("Yes" if x >= 30 else "No")


if __name__ == '__main__':
    resolve()
