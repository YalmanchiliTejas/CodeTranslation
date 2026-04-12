#!/usr/bin/python3

a, b, c, x, y = map(int, input().split())

min = float('inf')
for i in range(max(x, y) + 1):
    pa = (x - i) * a
    if pa < 0:
        pa = 0
    pb = (y - i) * b
    if pb < 0:
        pb = 0
    pc = c * 2 * i
    sum = pa + pb + pc
    if min > sum:
        min = sum

print(min)