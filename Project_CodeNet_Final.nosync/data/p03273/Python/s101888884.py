h, w = map(int, input().split())
a = []
for i in range(h):
	a.append(list(input()))


temp1 = []
temp2 = []
for i in range(len(a)):
	ff = 0
	for j in range(len(a[i])):
		if a[i][j] == '.':
			continue
		ff = 1
	if ff == 0:
		temp1.append(i)
temp1.sort(reverse=True)
for i in range(len(a[0])):
	ff = 0
	for j in range(len(a)):
		if a[j][i] == '.':
			continue
		ff = 1
	if ff == 0:
		temp2.append(i)
temp2.sort(reverse=True)
for i in range(len(temp1)):
	a.pop(temp1[i])
for i in range(len(temp2)):
	for k in range(len(a)):
		a[k].pop(temp2[i])

for i in range(len(a)):
	s = ''
	for j in range(len(a[i])):
		s += a[i][j]
	print(s)
