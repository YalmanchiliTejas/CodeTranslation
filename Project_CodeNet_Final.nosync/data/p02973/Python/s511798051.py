import bisect

n = int(input())
a = [int(input()) for _ in range(n)]
r = [-1] * n
for a in a:
    i = bisect.bisect_left(r, a)
    r[i - 1] = a
print(len(r) - r.count(-1))