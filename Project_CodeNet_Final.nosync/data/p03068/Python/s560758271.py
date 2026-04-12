# -*- coding: utf-8 -*-

n = int(input())

s = input()

k = int(input())

s1 = s[k-1]

for i in s:
    if i == s1:
        print(i, end='')
    else:
        print('*', end='')

