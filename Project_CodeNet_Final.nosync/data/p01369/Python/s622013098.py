lefthand = set("qwertasdfgzxcvb")
while True:
	line = raw_input()
	if line == "#": break
	prehand = line[0] in lefthand
	count = 0
	for c in line:
		if (c in lefthand) != prehand:
			prehand = not prehand
			count += 1
	print count