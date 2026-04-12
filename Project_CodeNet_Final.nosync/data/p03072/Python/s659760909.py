# -*- coding: utf-8 -*-

n = input()

h = map(int, raw_input().split())

tempMax = 0
ans = 0;
for i in h:
    if i >= tempMax:
        ans += 1
        tempMax = i

print ans