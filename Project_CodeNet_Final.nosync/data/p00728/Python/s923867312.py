n = int(raw_input())
while n != 0:
	l = list()
	for i in range(n):
		l.append(int(raw_input()))
	print int((sum(l)-max(l)-min(l)) / (n-2))
	n = int(raw_input())