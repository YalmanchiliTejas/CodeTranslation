input()
ms = [int(i) for i in input().split()]
mh = 0
c = 0
for m in ms:
	if m >= mh:
		mh = m
		c += 1
print(c)
