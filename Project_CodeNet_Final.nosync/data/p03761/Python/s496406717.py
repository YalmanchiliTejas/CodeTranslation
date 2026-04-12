n = input()
a26 = [0 for _ in range(26)]

for i in range(n):
	s = raw_input()
	b26 = [0 for _ in range(26)]
	for j in range(len(s)):
		b26[ord(s[j]) - 97] += 1
	
	if i == 0:
		a26 = b26
	else:
		for j in range(26):
			a26[j] = min(a26[j], b26[j])

s = ""
for i in range(26):
	for _ in range(a26[i]):
		s += chr(97 + i)

print s