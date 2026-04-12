A, B, C, X, Y = map(int, input().split())
tmp = A*X + B*Y
if X >= Y:
    tmp = min(tmp,2*Y*C+(X-Y)*A)
else:
    tmp = min(tmp,2*X*C+(Y-X)*B)
tmp = min(tmp,max(X,Y)*2*C)
print(tmp)