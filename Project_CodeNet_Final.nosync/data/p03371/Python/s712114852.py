a, b, c, x, y = [int(i) for i in input().split(" ")]

price = a*x + b*y
a_num = x
b_num = y

while True:
	if a_num > 0:
		a_num -= 1
		next_price = price - a
	if b_num > 0:
		b_num -= 1
		next_price = next_price - b

	next_price = next_price + c*2
	if next_price < price:
		price = next_price
	else:
		print(price)
		break