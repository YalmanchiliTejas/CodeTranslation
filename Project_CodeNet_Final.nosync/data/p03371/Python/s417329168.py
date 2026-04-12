a, b, c, x, y = map(int, input().split())

high = max(x, y)
low = min(x, y)

if a + b <= c * 2:
	res = a * x + b * y
else:
	if high == x:
		res = low * c*2 + (high - low) * a
	else:
		res = low * c*2 + (high - low) * b
	res = min( res, c*2 * high )
print(res)

