A, B, C, X, Y = tuple(map(int, input().split(" ")))

half = 0
if C * 2 <= A:
    half = X * 2
if C * 2 <= B:
    half = max(Y * 2, half)
if C <= (A + B) // 2:
    half = max(half, min(X, Y) * 2)

cost = half * C
X -= half // 2
Y -= half // 2

if X > 0:
    cost += X * min(A, C * 2)
if Y > 0:
    cost += Y * min(B, C * 2)

print(cost)
