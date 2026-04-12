import bisect as bs
import collections

n = int(input())
alist = [0]*n
for i in range(n):
    alist[i] = int(input())

col = collections.deque()
min_ = 10000000000

for a in alist:
    if a <= min_:
        col.appendleft(a)
    else:
        index = bs.bisect_left(col, a) - 1
        col[index] = a
    min_ = col[0]

print(len(col))
