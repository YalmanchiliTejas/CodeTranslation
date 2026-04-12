import bisect
import collections
n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
m = collections.deque([])
for i in range(0, n):
    j = bisect.bisect_left(m, a[i])
    if j == 0:
        m.appendleft(a[i])
    else:
        m[j - 1] = a[i]
print(len(m))