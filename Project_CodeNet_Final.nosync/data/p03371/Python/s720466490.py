A, B, C, X, Y = map(int, input().split())
    

if X >= Y:
    ans = min(A*X + B*Y, 2*C*Y + A*(X-Y), 2*C*X)
else:
    ans = min(A*X + B*Y, 2*C*X + B*(Y-X), 2*C*Y)

print(ans)