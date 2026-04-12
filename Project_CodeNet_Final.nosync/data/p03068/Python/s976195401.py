# -*- coding: utf-8 -*-
n = int(raw_input())
s = str(raw_input())
k = int(raw_input())

c = (list(s))[k-1]

def sub(x):
    global c
    if x != c:
        return "*"
    else:
        return x

ans = "".join(map(sub, s.strip()))

print ans