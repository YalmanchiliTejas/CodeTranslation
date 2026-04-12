A, B, C, X, Y = map(int, input().split())

if A+B <= 2*C:
    answer = A * X + B * Y
else:
    answer = C * min(X, Y) * 2
    if X < Y:
        answer += min(B, C * 2) * (Y - X)
    else:
        answer += min(A, C * 2) * (X -Y)

print(answer)