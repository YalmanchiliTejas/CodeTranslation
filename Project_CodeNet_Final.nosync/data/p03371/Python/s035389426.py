A, B, C, X, Y = map(int, input().split())

cost = 0

ab = min(X, Y)
cost += min(ab * 2 * C, (A + B) * ab)
X -= ab
Y -= ab

cost += min(C * 2, A) * X
cost += min(C * 2, B) * Y

print(cost)