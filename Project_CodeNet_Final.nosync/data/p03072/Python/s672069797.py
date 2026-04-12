# -*- coding: utf-8 -*-

n = int(input())

h = list(map(int, input().split()))

count = 1

for i in range(1, n):
    hli = h[:i+1]
    if h[i] >= max(hli):
        count += 1

print(count)
