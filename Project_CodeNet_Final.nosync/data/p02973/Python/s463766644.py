import bisect
inf = 1000000009
n = int(input())
a = [int(input()) for i in range(n)]
b = [inf] * (n + 10)
for i in range(n):
    j = bisect.bisect_right(b, -a[i], 0, hi = len(b))
    b[j] = -a[i]
print(bisect.bisect_left(b, inf, 0, hi = len(b)))