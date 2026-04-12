N = int(input())
*H, = map(int, input().split())

c = 0
mh = H[0]
for h in H:
	if mh <= h:
		c += 1
		mh = max(mh, h)
	else:
		continue
print(c)
