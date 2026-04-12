# -*- coding: utf-8 -*-
import bisect

n = int(input())
a = [0 for _ in range(n)]
for i in range(n):
    a[i] = -int(input())


LIS = list()
for i in a:
    j = bisect.bisect_right(LIS, i)
    if len(LIS) == j:
        LIS.append(i)
    else:
        LIS[j] = i

print(len(LIS))