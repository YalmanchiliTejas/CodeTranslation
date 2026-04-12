#!usr/bin/env python
# -*- coding: utf-8 -*-

while True:
        n = int(raw_input())
        if n == 0:
                break
        list = []
        for i in range(n):
                list.append(int(raw_input()))
        print (sum(list) - max(list) - min(list))/(n-2)