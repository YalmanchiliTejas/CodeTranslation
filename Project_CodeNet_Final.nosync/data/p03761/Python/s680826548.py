n = int(raw_input())

slist = []
for i in range(0, 26):
	slist.append(50)
	
for i in range(0, n):
	alphabet = []
	for j in range(0, 26):
		alphabet.append(0)
	s = raw_input()
	for j in range(0, len(s)):
		alphabet[ord(s[j])-97] += 1
	for j in range(0, 26):
		if alphabet[j] < slist[j]:
			slist[j] = alphabet[j]

ans = ''
for i in range(0, 26):
	c = chr(i+97)
	for j in range(0, slist[i]):
		ans += c

print ans