L = "qwertasdfgzxcvb"
while 1:
	key = raw_input()
	if key == "#": break
	c = 0
	h = 1 if key[0] in L else 0
	for i in range(1,len(key)):
		p = 1 if key[i] in L else 0
		c += abs(h-p)
		h = p
	print c