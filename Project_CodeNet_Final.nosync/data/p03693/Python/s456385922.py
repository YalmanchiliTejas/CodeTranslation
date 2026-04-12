# -*- coding: utf-8 -*-S
r,g,b = [int(i) for i in input().split()]

X = 100 * r + 10 * g + b
if X % 4 == 0:
    print("YES")
else:
    print("NO")
