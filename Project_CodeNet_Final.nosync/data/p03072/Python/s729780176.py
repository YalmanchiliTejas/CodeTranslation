# -*- coding: utf-8 -*-
import re, sys

input()
mountains = list(map(int, input().split()))

max_height = mountains[0]
count = 0
for i in range(len(mountains)):
	if mountains[i] >= max_height:
		max_height = mountains[i]
		count += 1

print(count)