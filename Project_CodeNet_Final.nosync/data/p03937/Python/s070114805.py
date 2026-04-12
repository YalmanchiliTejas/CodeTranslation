h, w = map(int, input().split())
a = []
for _ in range(h):
	a += list(input())

if a.count("#") == h + w - 1:
	print("Possible")
else:
	print("Impossible")