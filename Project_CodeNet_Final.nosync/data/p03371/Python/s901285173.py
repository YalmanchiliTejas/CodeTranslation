A,B,C,X,Y = map(int, raw_input().split())
  
m = min(X,Y)
M = max(X,Y)
result = 0
if A + B >= 2 * C:
    result += C * m * 2
    if m == X:
        result += (Y - X) * min(B, 2*C)
    else:
        result += (X - Y) * min(A, 2*C)
else:
    result =  A * X + B * Y

print(result)