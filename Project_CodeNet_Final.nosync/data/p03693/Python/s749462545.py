list = input().split()
r = int(list[0])
g = int(list[1])
b = int(list[2])

if (100*r+10*g+b)%4 == 0:
	print("YES")
else:
	print("NO")
