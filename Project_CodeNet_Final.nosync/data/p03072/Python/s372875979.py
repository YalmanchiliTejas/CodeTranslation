# -*- coding: utf-8 -*-

n = int(input())
h = list(map(int, input().split()))

max_h = []
for i in range(n):
    if i == 0:
        max_h.append(h[0])
    else:
        max_h.append(max(h[i],max_h[i-1]))
#print(max_h)

count = 0
for i in range(n):
    if h[i] >= max_h[i]:
        count += 1
print(count)