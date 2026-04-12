A, B, C, X, Y = map(int, input().split())


if A + B >= 2 * C:
    if X >= Y:
        cnt = min((C * 2 * Y) + A * (X - Y), (C * 2 * X))
    else:
        cnt = min((C * 2 * X) + B * (Y - X), (C * 2 * Y))
    
else:
    cnt = (A * X) + (B * Y)
    
print(cnt)