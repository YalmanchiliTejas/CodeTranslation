#!/usr/bin/env python3
n = int(input())
a = list(map(int, input().split()))
b = sorted(a)
for a_i in a:
    if a_i <= b[n // 2 - 1]:
        c = b[n // 2]
    else:
        c = b[n // 2 - 1]
    print(c)
