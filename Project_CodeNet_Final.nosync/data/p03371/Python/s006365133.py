A, B, C, X, Y = list(map(int, input().split()))

count = 0
if 2*C < A + B:
	count += min(X, Y) * 2*C
	if X > Y:
		if 2*C < A:
			count += (X - Y) * 2*C
		else:
			count += (X - Y) * A
	else:
		if 2*C < B:
			count += (Y - X) * 2*C
		else:
			count += (Y - X) * B
else:
	count += A*X + B*Y

print(count)

