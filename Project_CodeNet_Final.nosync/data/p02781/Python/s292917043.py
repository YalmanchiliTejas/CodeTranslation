''' بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ '''
#codeforces
gi = lambda : list(map(int,input().split()))
s = input()
n, = gi()
ans = 0
mag = len(s) - 1
#corner cases:
if len(s) <= 7:
	s = int(s)
	for k in range(s + 1):
		if len(str(k)) - str(k).count("0") == n:
			ans += 1
	print(ans)
	exit()
while mag - n >= 0:
	a = 9
	b = 1
	c = 1
	if n > 2:
		c = 81 * ((mag - 1) * (mag - 2) // 2)
	elif n > 1:
		b = 9 * (mag - 1)
	ans += a * b * c
	#print(mag, a, b, c, ans)
	mag -= 1
mag = len(s)
a = int(s[0]) - 1
b, c = 1, 1
if n > 2:
	c = 81 * ((mag - 1) * (mag - 2) // 2)
elif n > 1:
	b = 9 * (mag - 1)
ans += a * b * c
a = b = c = 1
if n == 1:
	print(ans + 1)
	exit()
if n > 1:
	i = -1
	for k in range(1, len(s)):
		if s[k] != "0":
			i = k
			break;
	if i != -1:
		a = int(s[i]) - 1
		if n > 2:
			b = len(s) - i - 1
			b *= 9
		ans += a * b
		a = b = 1
		if n > 2:
			x = len(s) - i - 1
			a = 81 * (x * (x - 1)) // 2
		else:
			a = 9 * (len(s) - i - 1)
		ans += a
	if n > 2:
		a = b = c = 1
		j = -1
		for k in range(i + 1, len(s)):
			if s[k] != "0":
				j = k
				break;
		if j != -1:
			ans += 9 * (len(s) - j - 1) + int(s[j])
	else:
		ans += 1
print(ans)