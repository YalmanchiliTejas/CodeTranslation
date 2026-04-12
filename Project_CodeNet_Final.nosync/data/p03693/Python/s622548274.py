import sys

sys.setrecursionlimit(10 ** 7)
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    r, g, b = input().split()
    number = int(r + g + b)
    print("YES" if number % 4 == 0 else "NO")


if __name__ == '__main__':
    resolve()
