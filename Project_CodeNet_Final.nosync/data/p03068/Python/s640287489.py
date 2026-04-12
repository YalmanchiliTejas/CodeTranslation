# -*- coding: utf-8 -*-
n = int(input())
s = input()
k = int(input())

selected = s[k - 1]
print(''.join(['*' if l != selected else l for l in s ]))