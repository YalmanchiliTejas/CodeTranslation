A, B, C, X, Y = [int(x) for x in raw_input().split()]
s = 0
p = min(X, Y)
X -= p
Y -= p
s += p * min(A+B, 2*C)
s += X * min(A, 2*C)
s += Y * min(B, 2*C)
print s