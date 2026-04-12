# coding: utf-8

n = int(input())
hs = [int(x) for x in input().split()]

max_h = 0
count = 0

for h in hs:
    if h >= max_h:
        count += 1
        max_h = h

print(count)
