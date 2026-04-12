# -*- coding: utf-8 -*-
# input
n = int(input())
list = [int(a) for a in input().split()]

counter = 1
for ii in range(1, n):
    flag = 0
    for jj in range(0, ii):
        if list[ii] < list[jj]:
            flag = 1
            break
    if flag == 0:
        counter += 1

print(counter)
