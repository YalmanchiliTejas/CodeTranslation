import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

n, x = map(int, read().split())
a, b = [1], [1]
for i in range(n):
    a.append(a[i] * 2 + 3)
    b.append(b[i] * 2 + 1)


def check(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    elif x <= 1 + a[n - 1]:
        return check(n - 1, x - 1)
    else:
        return b[n - 1] + check(n - 1, x - 2 - a[n - 1]) + 1


print(check(n, x))
