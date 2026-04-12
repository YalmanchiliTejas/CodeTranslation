h, w = map(int, input().split())
s = h + w - 1
x = 0
for _ in range(h):
	x += input().count("#")

if s == x:
	print("Possible")
else:
	print("Impossible")