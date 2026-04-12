data = input().split()
r = int(data[0])
g = int(data[1])
b = int(data[2])

num = 10*g + b

if(num % 4 == 0):
	print("YES")
else:
	print("NO")

