str = input()
a,b = [int(x) for x in str.split()]
r = [0] * a
c = [0] * b
s = []
for i in range(0,a):
	str = input()
	s.append(str)
	for j in range(0,b):
		if str[j] == '#':
			r[i] += 1
			c[j] += 1
for i in range(0,a):
	if r[i] != 0:
		str = s[i]
		for j in range(0,b):
			if c[j] != 0:
				print(str[j],end="")
		print()
