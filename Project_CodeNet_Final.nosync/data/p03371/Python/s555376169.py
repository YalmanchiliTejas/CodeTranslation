# -*- coding: utf-8 -*-

A, B, C, X, Y = map(int, input().split())

ans = 9999999999
for z in range(0, 1000001, 2):
    result = A * max(0, int(X - (z / 2))) + B * max(0, int(Y - (z / 2))) + C * z
    ans = min(ans, result)
print(ans)