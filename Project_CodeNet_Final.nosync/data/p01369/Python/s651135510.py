LR = "qwertasdfgzxcvb yuiophjklnm"
while 1:
	key = raw_input()
	if key == "#": break
	c = 0
	h = LR.index(key[0])
	for i in range(1,len(key)):
		p = LR.index(key[i])
		if (h < 16 and p >= 16) or (h >= 16 and p < 16):
			c += 1
			h = p
	print c