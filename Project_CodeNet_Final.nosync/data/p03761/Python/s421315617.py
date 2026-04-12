n = int(input())

minlen = 100
mins = []
S = []
for i in range(n):
	s = list(input())
	s.sort()
	S.append(s)
	if len(s) < minlen:
		minlen = len(s)
		mins = s

mins = [c for c in mins]
s = ""
for c in mins:
	flag = True
	for l in S:
		if c in l:
			l.remove(c)
		else:
			flag = False
	if flag:
		s += c

print(s)