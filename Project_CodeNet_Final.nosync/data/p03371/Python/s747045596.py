A, B, C, X, Y = map(int, input().split())

pay = 0
same = min(X, Y)
pay += same * min(A + B, C * 2)

X -= same
Y -= same

pay += X * min(A, C * 2)
pay += Y * min(B, C * 2)

print(pay)