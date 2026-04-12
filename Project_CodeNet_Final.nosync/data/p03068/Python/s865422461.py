#!/usr/bin/env python3
n = int(input())
a = input()
k = int(input())
for i in range(n):
    if a[k-1] == a[i]: print(a[i],end="")
    else: print("*",end="")
