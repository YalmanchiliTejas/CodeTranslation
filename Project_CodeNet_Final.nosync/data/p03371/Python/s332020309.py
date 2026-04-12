A, B, C, X, Y = map(int, input().split())

print(min(A*X+B*Y, min(X, Y)*C*2 + (X-min(X, Y))*A+(Y-min(X, Y))*B, max(X, Y)*C*2))