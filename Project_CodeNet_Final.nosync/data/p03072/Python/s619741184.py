# -*- coding: utf-8 -*-
n = int(input())
ryokan = list(map(int, input().split()))
count = 0
max = 0

for i in ryokan:
    if i >= max:
        count += 1
        max = i

print(count)