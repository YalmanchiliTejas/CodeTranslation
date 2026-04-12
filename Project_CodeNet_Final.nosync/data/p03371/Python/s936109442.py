A, B, C, X, Y = map(int, input().split())
if 2*C < A+B:
    if X < Y:
        ans = 2*C*X+(Y-X)*min(B, 2*C)
    else:
        ans = 2*C*Y+(X-Y)*min(A, 2*C)
else:
    ans = A*X+B*Y
print(ans)
