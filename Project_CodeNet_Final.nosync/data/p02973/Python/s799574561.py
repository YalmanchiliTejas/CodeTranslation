# -*- coding: utf-8 -*-
from bisect import bisect_right

N = int(input())

columns = []


for _ in range(N):
    current = -int(input())
    index = bisect_right(columns, current)
    if len(columns) <= index:
        columns.append(current)
    else:
        columns[index] = current

print(len(columns))
