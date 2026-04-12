#! /usr/bin/env python3

A, B, AB, an, bn = map(int, input().split())
L = []
L += [AB*max(an, bn)*2]
L += [A*an+B*bn]
if an < bn:
    L += [B*(bn-an) + AB*min(an, bn)*2]
else:
    L += [A*(an-bn) + AB*min(an, bn)*2]
print(min(L))