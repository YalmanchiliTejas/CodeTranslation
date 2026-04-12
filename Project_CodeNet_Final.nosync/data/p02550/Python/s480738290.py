n,x,m = map(int, raw_input().split())
ans = 0

seen = {}
reverse = {}
c = 0
while(x not in seen):
	seen[x] = c
	reverse[c] = x
	c+=1
	x = (x**2) % m
#print seen[x], c-1 
#print [(key, reverse[key])for key in sorted(reverse.keys())]
def f(n,a,b,reverse):
	ans = 0
	#print a,b
	for i in xrange(b+1):
		if n > 0:
			ans += reverse[i]
			n-=1
		else:
			break
	if n > 0:
		t = sum([reverse[uu] for uu in xrange(a,b+1)] or [0])
		ans += n/(b-a+1) * t
		n %= (b-a+1)

		for i in xrange(a,b+1):
			if n > 0:
				ans += reverse[i]
				n-=1
			else:
				break

	return ans


print f(n, seen[x], c-1, reverse)


