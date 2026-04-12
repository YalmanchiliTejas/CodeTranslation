n = int(input())

s = []
for _ in range(n):
	temp = input()
	s.append((len(temp),list(temp)))

s.sort()

checker = sorted(s[0][1])
res = []
for ch in checker:
	truth = True
	for word in s:
		if ch not in word[1]:
			truth = False
			break
	if truth:
		res.append(ch)
		for word in s:
			word[1].remove(ch)

print(''.join(res))