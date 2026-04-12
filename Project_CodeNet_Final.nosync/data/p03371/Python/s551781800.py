a, b, c, x, y = map(int, input().split())
count = 0

if x >= y:
	i = a * (x - y) + c * y * 2
	j = a * x + b * y
	k = c * x * 2
	if i >= j and k >= j:
		count = j
	elif i >= k and j >= k:
		count = k
	elif j >= i and k >= i:
		count = i
else:
	i = b * (y - x) + c * x * 2
	j = a * x + b * y
	k = c * y * 2
	if i >= j and k >= j:
		count = j
	elif i >= k and j >= k:
		count = k
	elif j >= i and k >= i:
		count = i

print(count)