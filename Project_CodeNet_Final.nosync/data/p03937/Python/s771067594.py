H, W = map(int, input().split())
STAGE = [list(input()) for _ in range(H)]

ds = ((0, 1), (1, 0))
cp = [(0, 0)]
sc = 1

while cp:
	np = []
	for p in cp:
		y, x = p
		for d in ds:
			dy, dx = y + d[0], x + d[1]
			if 0 <= dy < H and 0 <= dx < W:
				if "#" == STAGE[dy][dx]:
					sc += 1
					if not (dy, dx) in np:
						np += [(dy, dx)]
						break
			else:
				continue
	#print(np)
	cp = np

c = 0
for line in STAGE:
	c += line.count("#")

print(["Possible", "Impossible"][not(sc == c)])
