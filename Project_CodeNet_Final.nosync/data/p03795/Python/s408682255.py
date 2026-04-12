import sys

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n = int(input())
    x = 800 * n
    y = (n // 15) * 200
    print(x - y)


if __name__ == '__main__':
    resolve()
