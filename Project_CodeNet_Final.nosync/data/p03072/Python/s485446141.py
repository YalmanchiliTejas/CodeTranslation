# -*- coding: utf-8 -*-
N = int(input())
H = list(map(int, input().split()))

ret = 0
highest = 0
for h in H:
    if h >= highest:
        highest = max(highest, h)
        ret += 1
print(ret)