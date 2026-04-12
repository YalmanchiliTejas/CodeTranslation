right = {"y", "u", "i", "o", "p", "h", "j", "k", "l", "n", "m"}
while 1:
	key_input = raw_input()
	if key_input == "#":
		break
	hand = "N"
	count = 0
	for c in key_input:
		if c in right :
			if hand == "L":
				count += 1
			hand = "R"
		else :
			if hand == "R":
				count += 1
			hand = "L"
	print count