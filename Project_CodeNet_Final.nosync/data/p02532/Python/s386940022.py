n = input()
a = []
for i in xrange(n + 1):
	a.append([])
while True:
	x = raw_input().split()
	if x[0] =='push':
		a[int(x[1])].append(x[2])
	elif x[0] == 'pop':
		print a[int(x[1])].pop()
	elif x[0] =='move':
		a[int(x[2])].append(a[int(x[1])].pop())
	else:
		break