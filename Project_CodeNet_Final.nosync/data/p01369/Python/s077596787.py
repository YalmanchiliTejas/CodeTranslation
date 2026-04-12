while True:
	s = input()
	if s == "#":
		break
	prv,ans = -1,0
	for c in s:
		now = (c in "yuiophjklnm")
		ans += (prv != now)
		prv = now
	print(ans - 1)
