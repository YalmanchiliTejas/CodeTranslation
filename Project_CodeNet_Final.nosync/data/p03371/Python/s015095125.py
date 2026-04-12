a, b, c, x, y = map(int,input().split())

count = a * x + b * y

if x >= y:
	for i in range(x+1):
		if i > y:
			tmp = a * (x-i) + c * (i*2)
		else:
			tmp = a * (x-i) + b * (y-i) + c * (i*2)
		count = min(count, tmp)
else:
	for j in range(y+1):
		if j > x:
			tmp = b * (y-j) + c * (j*2)
		else:
			tmp = a * (x-j) + b * (y-j) + c * (j*2)
		count = min(count,tmp)

print(count)




		
	
	
	