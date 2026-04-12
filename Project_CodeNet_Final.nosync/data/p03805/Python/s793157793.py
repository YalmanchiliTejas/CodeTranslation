#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from fractions import gcd

def readln():
    _res = list(map(int,str(input()).split(' ')))
    return _res

def dfs(deep,now,v):
    if deep == n:
        return 1
    res = 0
    for i in range(1,n+1):
        if v[i] == 0 and e[now][i] == 1:
            v[i] = 1
            res = res + dfs(deep+1, i, v)
            v[i] = 0
    return res


a = readln()
n,m = a[0],a[1]
e = [[0 for i in range(0,n+1)] for j in range(0,n+1)]
for i in range(0,m):
    a = readln()
    e[a[0]][a[1]] = 1
    e[a[1]][a[0]] = 1
v = [0 for i in range(0,n+1)]
v[1] = 1
print(dfs(1,1,v))
