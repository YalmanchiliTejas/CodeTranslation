A, B, C, X, Y = map(int, input().split())

if A+B <= 2*C:
    ans = A*X + B*Y
else:
    if X < Y:
        A, B, X, Y = B, A, Y, X
    ans = min(C*2*Y + A*(X-Y), C*2*X)

print(ans)