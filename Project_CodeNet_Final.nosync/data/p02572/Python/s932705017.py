#!/usr/bin python3
# -*- coding: utf-8 -*-

mod = 10**9+7
n = int(input())
a = list(map(int, input().split()))
s = 0
ss = 0
for ai in a:
    s += ai
    ss += ai*ai
    s %=mod
    ss %=mod

x = pow(2,mod-2,mod)
ret = (s*s-ss)%mod
ret = ret*x
ret %=mod

print(ret)
