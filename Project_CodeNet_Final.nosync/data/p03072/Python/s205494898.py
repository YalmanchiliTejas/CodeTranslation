# -*- coding: utf-8 -*-
n = int(input())
hs = list(map(int, input().split()))

h_max = hs[0]
viewable = [hs[0]]
for i in range(1, n):
    h_height = hs[i]
    if h_height < h_max:
        continue
    h_max = h_height
    viewable.append(h_height)

print(len(viewable))