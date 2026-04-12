# -*- coding: utf-8 -*-

N = int(input())
H = list(map(int, input().split()))

max_h = 0
cnt = 0
for h in H:
    if h >= max_h:
        max_h = h
        cnt += 1
print(cnt)