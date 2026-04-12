import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

n, *a = map(int, read().split())
a.sort()
a1 = 2 * (sum(a[(n + 1) // 2:]) - sum(a[:(n + 1) // 2]))
a2 = 2 * (sum(a[n // 2:]) - sum(a[:n // 2]))
if n % 2 == 0:
    v = a[n // 2] - a[n // 2 - 1]
    a1 -= v
    a2 -= v
else:
    a1 += a[n // 2 - 1] + a[n // 2]
    a2 -= a[n // 2 + 1] + a[n // 2]
print(max(a1, a2))
