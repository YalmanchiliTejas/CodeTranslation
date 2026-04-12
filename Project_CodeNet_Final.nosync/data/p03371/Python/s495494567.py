a,b,c,x,y = map(int,input().split())

smallestSum = 0
tempSum = 0

smallestSum = a * x + b * y

if x < y:
	tempSum = c * x * 2 + b * (y - x)
	if tempSum < smallestSum:
		smallestSum = tempSum
	tempSum = c * y * 2
	if tempSum < smallestSum:
		smallestSum = tempSum
else:
	tempSum = c * y * 2 + a * (x - y)
	if tempSum < smallestSum:
		smallestSum = tempSum
	tempSum = c * x * 2
	if tempSum < smallestSum:
		smallestSum = tempSum

print(smallestSum)