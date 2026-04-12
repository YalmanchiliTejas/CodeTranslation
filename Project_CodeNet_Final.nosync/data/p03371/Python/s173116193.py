# -*- coding: utf-8 -*-

# input
A, B, C, X, Y = map(int, input().split())

# solve & output
print(min(A * X + B * Y, A * max(0, (X - Y)) + C * 2 * Y, B * max(0, (Y - X)) + C * 2 * X, C * 2 * max(X, Y)))
