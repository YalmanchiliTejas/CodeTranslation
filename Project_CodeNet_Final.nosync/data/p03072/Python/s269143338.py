# -*- coding: utf-8 -*-
_ = int(input())
h = map(int, input().split())

highest = -1
n = 0
for i in h:
    if i >= highest:
        n += 1
        highest = i

print(n)
