import sys

sys.setrecursionlimit(10 ** 7)
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n, x = map(int, input().split())
    a, p = [1], [1]
    for i in range(n):
        a.append(a[i] * 2 + 3)
        p.append(p[i] * 2 + 1)

    def solve(n, x):
        if n == 0:
            return 1 if x == 1 else 0

        if x < 2:
            return 0

        if a[n] - 1 <= x:
            return p[n]

        if 1 + a[n] // 2 < x:
            return p[n - 1] + 1 + solve(n - 1, x - (a[n] // 2 + 1))
        elif 1 + a[n] // 2 == x:
            return p[n - 1] + 1
        else:
            return solve(n - 1, x - 1)

    print(solve(n, x))


if __name__ == '__main__':
    resolve()
