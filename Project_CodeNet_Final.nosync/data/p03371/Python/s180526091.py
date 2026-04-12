A, B, C, X, Y = map(int, input().split())

lst = []

lst.append(A * X + B * Y)
if X > Y:
    lst.append(A * (X-Y) + C * Y * 2)
    lst.append( C * X * 2)
else:
    lst.append(C * X * 2 + B * (Y - X))
    lst.append(C * Y * 2)
print(min(lst))
