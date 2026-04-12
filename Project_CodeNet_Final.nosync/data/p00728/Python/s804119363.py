# -*- coding: utf-8 -*-

n = int(raw_input())
while n != 0:
    list = []
    for i in range(n):
        list.append(int(raw_input()))
    print (sum(list)-max(list)-min(list))/(n-2)

    n = int(raw_input())