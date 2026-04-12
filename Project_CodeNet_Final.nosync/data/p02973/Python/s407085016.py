# -*- coding: utf-8 -*-
import bisect

n = int(input())
a = [int(input()) for _ in range(n)]

group_min = [a.pop()]
a.reverse()

for e in a:
    idx = bisect.bisect(group_min, e)
    if len(group_min) == idx:
        group_min.append(e)
    elif group_min[idx] > e:
        group_min[idx] = e
    else:
        # group_min[idx] == e:
        group_min.insert(idx, e)

print(len(group_min))
