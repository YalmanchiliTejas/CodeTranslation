x, y, z = map(int, input().split())
i = 1

while True:

	if x < (i * y) + ((i + 1) * z):
		print(i-1)
		exit()

	i += 1