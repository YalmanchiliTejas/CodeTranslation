import sys
import bisect

input = sys.stdin.readline
N = int(input())
A = [int(input()) for _ in range(N)]
# - bisect_right(=bisect)(iter, x): (iter[i] < x)を満たす最小のiを返す
# - bisect_left: (iter[i] <= x)を満たす最小のiを返す
c = []
for a in A:
    a *= -1
    i = bisect.bisect_right(c, a)
    if i == len(c):
        c.append(a)
    else:
        c[i] = a
print(len(c))
