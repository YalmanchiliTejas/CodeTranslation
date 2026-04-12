# -*- coding: utf-8 -*-

A, B, C, X, Y = list(map(int, input().split()))

cost = int(1e10)
for num_ac in range(0, int(1e5) + 1):
    num_A = max(0, X - num_ac)
    num_B = max(0, Y - num_ac)
    c = 2 * C * num_ac + A * num_A + B * num_B
    cost = min(c, cost)
print(cost)