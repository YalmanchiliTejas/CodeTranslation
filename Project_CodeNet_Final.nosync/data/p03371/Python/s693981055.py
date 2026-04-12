A, B, C, X, Y = map(int, input().split())

cost_1 = A*X + B*Y
cost_2 = C * max(X, Y) * 2

cost_3 = C * min(X, Y) * 2 + (X - min(X, Y))*A + (Y - min(X, Y))*B


print(min(cost_1, cost_2, cost_3))