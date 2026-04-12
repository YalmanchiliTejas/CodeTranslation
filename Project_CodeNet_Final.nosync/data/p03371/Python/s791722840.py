A, B, C, X, Y = map(int, input().split())
res = A*X + B*Y
for i in range(max(X,Y)):
    if i >= X:
        res = min(res-B+2*C,res)
    elif i >= Y:
        res = min(res-A+2*C,res)
    else:
        res = min(res-A-B+2*C,res)
print(res)