A, B, C, X, Y = map(int, input().split())
money = min(X, Y) * min(A + B, 2*C)
money += min(A*(X - min(X, Y)) + B*(Y - min(X, Y)), 2*C*abs(X - Y))
print(money)
