# -*- coding: utf-8 -*-

N = int(input())
h_list = list(map(int, input().split()))

max_h = 0
number = 0
for h in h_list:
    if h >= max_h:
        max_h = h
        number += 1

print (number)