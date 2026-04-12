#!/usr/bin/env python3
# -*- coding: utf-8 -*-

n = int(input())
l = [int(e) for e in input().split()]

h = l[0]
count = 1
for i in range(1, n):
	if h <= l[i]:
		h = l[i]
		count += 1

print(count)

