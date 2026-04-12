A, B, C, X, Y = map(int, input().split())

if Y == X:
    if C * 2 < A + B:
        res = C * X * 2
    else:
        res = A * X + B * Y
        
elif Y < X:
    if C * 2 <= A + B:
        res = C * Y * 2
        if C * 2 <= A:
            res += (X - Y) * 2 * C
        else:
            res += (X - Y) * A
    else:
        res = A * X + B * Y

else:
    if C * 2 <= A + B:
        res = C * X * 2
        if C * 2 <= B:
            res += (Y - X) * 2 * C
        else:
            res += (Y - X) * B
    else:
        res = A * X + B * Y

print(res)