#!/usr/bin python3
# -*- coding: utf-8 -*-

n, x, m = map(int, input().split())

s = set([])
v = []
for i in range(m+1):
    s.add(x)
    v.append(x)
    x = pow(x,2,m)
    if x in s:
        break
st = v.index(x)
lp = len(v)-st
lps = sum(v[st:])

k = (n-(st+lp)+(lp-1))//lp
ret = lps * k
n -= lp * k
ret += sum(v[:n])

print(ret)