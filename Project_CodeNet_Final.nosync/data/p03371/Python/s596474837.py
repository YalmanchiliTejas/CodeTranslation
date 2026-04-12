a,b,c,x,y = map(int,input().split())
single = (a*x)+(b*y)
ab_pizza2 = c*max(x,y)*2
if x > y:
	ab_pizza = c*(2*y)
	x -= y
	ab_pizza += a*x
else:
	ab_pizza = c*(2*x)
	y -= x
	ab_pizza += b*y
total = min(single,ab_pizza,ab_pizza2)
print(total)