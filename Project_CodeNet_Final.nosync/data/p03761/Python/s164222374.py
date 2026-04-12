N = int(input())
countlist = []
for i in range(0, N):
	lst = []
	for j in range(0, 26):
		lst.append(0)
	countlist.append(lst)
for i in range(0, N):
	S = input()
	for j in range(0, len(S)):
		countlist[i][ord(S[j])-97] += 1
countmin = []
for i in range(0, 26):
	min = 5000000000000000
	for j in range(0, N):
		if countlist[j][i] < min: min = countlist[j][i]
	countmin.append(min)
ans = ''
for i in range(0, 26):
	for j in range(0, countmin[i]):
		ans = ans + chr(i+97)
print(ans)