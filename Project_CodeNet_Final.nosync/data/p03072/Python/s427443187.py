# -*- coding: utf-8 -*-
N = int(input())
lst = list(map(int,input().split()))

max = 0
sum = 0
for i in range(N):
    if max <= lst[i]:
        sum = sum + 1
        max = lst[i]

print(sum)