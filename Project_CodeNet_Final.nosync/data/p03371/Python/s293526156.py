def smaller(x, y):
	if x < y: return x
	return y

A, B, AB, X, Y = map(int, input().split())
sum = 0
if A + B <= 2 * AB:
	sum += A * X + B * Y
else:
	pizzaset = 2 * smaller(X, Y)
	sum += pizzaset * AB
	X -= pizzaset // 2
	Y -= pizzaset // 2
	if X == 0:
		if B <= 2 * AB:
			sum += B * Y
		else:
			sum += 2 * Y * AB
	else:
		if A <= 2 * AB:
			sum += A * X
		else:
			sum += 2 * X * AB
print(sum)