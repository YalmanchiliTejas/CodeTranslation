l = map(int, raw_input().split())
a = l[0]
b = l[1]
c = l[2]
x = l[3]
y = l[4]

if a+b <= 2*c:
	price = a*x + b*y
	tmp = 0
else:
	if x < y:
		price = 2*c*x
		tmp = y-x
	else:
		price = 2*c*y
		tmp = x-y

if tmp !=0:
	if x > y:
		if tmp*a > tmp*2*c:
			price += tmp*2*c
		else:
			price += tmp*a
	elif y > x:
		if tmp*b > tmp*2*c:
			price += tmp*2*c
		else:
			price += tmp*b

print price