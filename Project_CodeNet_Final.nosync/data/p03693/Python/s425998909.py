r, g, b = map(int, input().split())
add = str(r) + str(g) + str(b)
add = int(add)

if add%4 == 0:
	print("YES")
else:
	print("NO")