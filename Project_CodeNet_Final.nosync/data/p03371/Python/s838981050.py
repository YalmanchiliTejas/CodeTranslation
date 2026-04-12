A, B, C, X, Y = map(int, input().split())
print(min(A*X+B*Y, X*C*2 + max(0, Y-X)*B, Y*C*2 + max(0, X-Y)*A))
