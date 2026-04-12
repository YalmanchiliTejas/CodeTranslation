# -*- coding: utf-8 -*-

N = int(input())
As = list(map(int, input().split()))
b = []
i = len(As) - 1
while i >= 0:
    b.append(As[i])
    i -= 2

i = len(As) % 2
while i<len(As):
    b.append((As[i]))
    i += 2

print(*b)
