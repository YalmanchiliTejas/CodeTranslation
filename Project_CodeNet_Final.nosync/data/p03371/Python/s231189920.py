A, B, C, X, Y = map(int, input().split())

if X == Y:
    ans = min(A*X+B*Y, C*X*2)
elif X > Y:
    ans = min(A*X+B*Y, C*X*2, 2*C*Y+A*(X-Y))
else:
    ans = min(A*X+B*Y, C*Y*2, 2*C*X+B*(Y-X))

print(ans)