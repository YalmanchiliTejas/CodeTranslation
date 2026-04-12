# -*- coding: utf-8 -*-

n = int(input())
s = input()
k = int(input())

t = s[k-1]

s_list = list(s)

for i in range(n):
    if s[i] != t:
        s_list[i] = '*'

s_changed = "".join(s_list)
print(s_changed)