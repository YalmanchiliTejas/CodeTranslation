n = int(raw_input())
a = map(int, raw_input().split())
ret = 0
while True:
	mp = 0
	for i in range(n):
		if a[i] > a[mp]:
			mp = i
	if a[mp] < n:
		break
	c = a[mp] // n
	ret += c
	a[mp] = a[mp] % n
	for i in range(n):
		if i != mp:
			a[i] += c
print ret