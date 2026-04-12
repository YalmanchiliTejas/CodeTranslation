A, B, C, X, Y = map(int, input().split())

a = A*X+B*Y
b = max(X, Y) * 2 * C

if X > Y:
    c = Y*2 * C + (X-Y) * A
else:
    c = X*2 * C + (Y-X) * B

print(min(a, b, c))