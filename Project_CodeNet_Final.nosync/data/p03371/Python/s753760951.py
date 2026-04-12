A, B, C, X, Y = map(int,input().split())
value = 0
ans = []
ans.append(max(X,Y) * 2*C)
if X > 0 and Y > 0 and A + B > 2*C:
    m = min(X, Y)
    value += m * 2*C
    X = X - m
    Y = Y - m
value += (X * A + Y * B)
ans.append(value)
print(min(ans))