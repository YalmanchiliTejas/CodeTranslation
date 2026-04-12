# -*- coding: utf-8 -*-
from bisect import bisect_right, bisect_left
N = int(input())
a_list = [int(input()) for _ in range(N)]

color_list = [1]
for a in a_list:
    a *= -1
    index = bisect_right(color_list, a)
    if index < len(color_list):
        color_list[index] = a
    else:
        color_list.append(a)
#     print(color_list, a)
print(len(color_list))