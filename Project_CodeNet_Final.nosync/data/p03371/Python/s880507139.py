A,B,C,X,Y = map(int, input().split())
a = min(A+B, 2*C)
if X <= Y:
    ans = a * X + (Y - X) * min(B, 2*C)
else:
    ans = a * Y + (X - Y) * min(A, 2*C)
print(ans)