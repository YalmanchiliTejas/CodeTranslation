l = []
s = set()
while True:
	n, a = input()
	if n == a == 0:
		break;
	l.append(a)
	s.add(a)

s = list(s)
s.reverse()
while True:
	try:
	    n = input()
	except:
		break
	print(s.index(l[n-1])+1)