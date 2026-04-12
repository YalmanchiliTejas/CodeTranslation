#!/usr/bin/env python3
import re

n = int(input())
s = input()
k = int(input())

save = []

for i in range(n):
    if(s[i] != s[k-1]):
        save.append('*')
    else:
        save.append(s[i])

for i in range(len(save)):
    print(save[i], end = '')