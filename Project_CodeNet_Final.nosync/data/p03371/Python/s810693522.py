import sys
import math

A, B, C, X, Y = map(int, input().split())

ans = 10**15
a = []

for i in range(max(X, Y)+1):
    if X-i < 0:
        money = B*(Y-i) + 2 * C * i
    elif Y-i < 0:
        money = A*(X-i) + 2 * C * i
    else:
        money = A*(X-i) + B*(Y-i) + 2*C*i
    a.append(money)


print(min(a))