import sys

sys.setrecursionlimit(10 ** 7)
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n, k = map(int, input().split())
    if k == 0:
        print(n ** 2)
        exit()
        
    res = 0
    for b in range(1, n + 1):
        q, r = divmod(n, b)
        res += max(0, (b - 1 - (k - 1))) * q + max(0, r - (k - 1))
    print(res)


if __name__ == '__main__':
    resolve()
