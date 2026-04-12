# -*- coding: utf-8 -*-

r, g, b = map(int, input().split())

rgb = str(r)+str(g)+str(b)

n = int(rgb)

if n%4 == 0:
    print("YES")
else:
    print("NO")