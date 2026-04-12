# -*- coding: utf-8 -*-
n = int(input())
h = list(map(int, input().split()))
tmp_max = 0
count = 0
for hi in h:
    if tmp_max <= hi:
        tmp_max = hi
        count += 1
print(count)
