rgb = list(map(int, input().split(" ")))
if (rgb[1]*10+rgb[2]) % 4 == 0:
	print("YES")
else:
	print("NO")