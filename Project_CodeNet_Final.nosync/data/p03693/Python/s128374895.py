x, y, b = map(str, input().split())

a = int(x + y + b)
if a % 4 == 0 :
	print("YES")
else:
	print("NO")