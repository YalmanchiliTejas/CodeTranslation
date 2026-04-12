import sys
sys.setrecursionlimit(10**9)
A, B, C, X, Y = map(int, input().split())

cost1 = A * X + B * Y
cost2 = max(X, Y) * 2 * C
if X <= Y:
    cost3 = X * 2 * C + (Y - X) * B
else:
    cost3 = Y * 2 * C + (X - Y) * A

print(min([cost1, cost2, cost3]))
