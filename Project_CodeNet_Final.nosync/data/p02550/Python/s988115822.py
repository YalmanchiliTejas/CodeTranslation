#!/usr/bin/python3
# -*- coding: utf-8 -*-
n, x, m = map(int, input().split())
x_set = set()
x_list = []
for i in range(n):
    if x not in x_set:
        x_set.add(x)
        x_list.append(x)
    else:
        break
    x = x**2 % m
total = 0
start = n
for i in range(n):
    if x_list[i] == x:
        start = i
        break
    else:
        total += x_list[i]
if start != n:
    m = len(x_list) - start
    k = (n - start) // m
    total += k * sum(x_list[start:])
    for i in range(0, n - k * m - start):
        total += x_list[start + i]
print(total)