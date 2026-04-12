A, B, C, X, Y = map(int,input().split())

if A + B < 2 * C:
    print(A * X + B * Y)
elif min(X, Y) * 2 * C + abs(X - Y)*( A if X > Y  else B) > (max(X , Y) * 2 * C):
    print(max(X , Y) * 2 * C)
else:
    print(min(X, Y) * 2 * C + abs(X - Y)*( A if X > Y  else B) )