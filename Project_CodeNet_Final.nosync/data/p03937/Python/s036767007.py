H, W = list(map(int, input().split()))
A = []

for i in range(H):
	A.append(list(input()))

judge = "Possible"
x = 0
y = 0
for i in range(H + W - 2):
	if x == W - 1:
		if A[y + 1][x] == "#":
			y += 1
		else:
			judge = "Impossible"
			break
	elif y == H - 1:
		if A[y][x + 1] == "#":
			x += 1
		else:
			judge = "Impossible"
			break

	else:
		if A[y + 1][x] == "#":
			if A[y][x + 1] == "#":
				judge = "Impossible"
				break
			else:
				y += 1
		else:
			if A[y][x + 1] == "#":
				x += 1
			else:
				judge = "Impossible"
				break

s = 0
for i in range(H):
	s += A[i].count("#")

if s != H + W - 1:
	judge = "Impossible"

if A[0][0] != "#":
	judge = "Impossible"

if A[H - 1][W - 1] != "#":
	judge = "Impossible"

print(judge)