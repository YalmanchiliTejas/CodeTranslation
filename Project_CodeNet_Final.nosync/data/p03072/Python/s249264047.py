# coding: utf-8
# Your code here!

import itertools

N = int(input())
H = list(map(int, input().rstrip().split()))

cnt = 0
prev_max_height = 0

for h in H:
    if prev_max_height <= h:
        prev_max_height = h
        cnt += 1

out = cnt

print(out)