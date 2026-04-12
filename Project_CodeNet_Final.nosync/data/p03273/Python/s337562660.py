H, W = map(int, input().split())
STAGE = [input() for _ in range(H)]

ccheck = 0
for i, l in enumerate(STAGE):
	ccheck |= int(l.replace("#", "1").replace(".", "0"), 2)

for l in STAGE:
	if "#" not in l:
		continue
	for f, c in zip(format(ccheck, "b").zfill(W), l):
		if "1" == f:
			print(c, end="")
	print("")
