import sys

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    a, b, c, x, y = map(int, input().split())
    c *= 2
    if a + b > c:
        cost1 = max(x, y) * c
        cost2 = min(x, y) * c
        plus = ((y - x) * b) if x < y else (x - y) * a
        res = min(cost1, cost2 + plus)
    else:
        res = x * a + y * b
    print(res)

if __name__ == '__main__':
    resolve()
