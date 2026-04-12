A, B, C, X, Y = map(int, input().split())

res = A*X+B*Y
res = min(X*C*2 + max(Y-X, 0)*B, res)
res = min(Y*C*2 + max(X-Y, 0)*A, res)

print(res)