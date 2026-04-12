def smaller(x, y):
	if x < y:
		return x
	return y

N = int(input())
anscounter = []
for i in range(0, 26):
	anscounter.append(0)
S = input()
for i in range(0, len(S)):
	anscounter[ord(S[i])-97] += 1
for i in range(1, N):
	tmpcounter = []
	for j in range(0, 26):
		tmpcounter.append(0)
	newS = input()
	for j in range(0, len(newS)):
		tmpcounter[ord(newS[j])-97] += 1
	for j in range(0, 26):
		anscounter[j] = smaller(anscounter[j], tmpcounter[j])
ans = ''
for i in range(0, 26):
	for j in range(0, anscounter[i]):
		ans = ans + str(chr(i+97))
print(ans)