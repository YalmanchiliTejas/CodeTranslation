# -*- coding: utf-8 -*-

X, Y, Z = map(int, input().split())

ans = (X - Z) // (Y + Z)
print(ans)
