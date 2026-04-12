import sys

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n, k = map(int, input().split())

    if k == 0:
        print(n ** 2)
        exit()

    res = 0
    for b in range(1, n + 1):
        res += n // b * max(0, b - k)
        res += max(0, n % b + 1 - k)
    print(res)


if __name__ == '__main__':
    resolve()
