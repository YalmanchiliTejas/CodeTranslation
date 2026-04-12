A, B, C, X, Y = map(int, input().split())
com = min(X, Y)
min_cost = min(A+B, C*2)

if min_cost * max(X, Y) < min_cost * com  + A * (X - com) + B * (Y - com):
    print(min_cost * max(X, Y))
else:
    print(min_cost * com  + A * (X - com) + B * (Y - com))