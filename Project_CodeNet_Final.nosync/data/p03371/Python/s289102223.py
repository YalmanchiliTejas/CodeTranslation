def smaller(x, y):
	if x < y: return x
	return y
A, B, C, X, Y = map(int, raw_input().split())
sum = 0
if A+B > 2 * C:
	c = smaller(X, Y)
	sum += c * 2 * C
	X -= c
	Y -= c
	if A > 2 * C: sum += X * 2 * C
	else: sum += X * A
	if B > 2 * C: sum += Y * 2 * C
	else: sum += Y * B
else:
	sum = A * X + B * Y
print sum