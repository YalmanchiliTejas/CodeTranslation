A, B, C, X, Y = map(int, input().split())
minv = A*X + B*Y

tmp = C*X*2
if X > Y:
    minv = min(minv, tmp)
else:
    minv = min(minv, tmp+(Y-X)*B)

tmp = C*Y*2
if Y > X:
    minv = min(minv, tmp)
else:
    minv = min(minv, tmp+(X-Y)*A)
print(minv)
