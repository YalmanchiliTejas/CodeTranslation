h, w = map(int, input().split())
a = []
for i in range(h):
	a.append(input())
ind1 = []
for i in range(h):
	if "#" in a[i][:]:
		ind1.append(i)
ind2 = []
for i in range(w):
	judge = 0
	for j in range(h):
		if "#" == a[j][i]:
			judge = 1
	if judge:
		ind2.append(i)
for i in range(len(ind1)):
	s = []
	for j in range(len(ind2)):
		s.append(a[ind1[i]][ind2[j]])
	print("".join(map(str, s)))
		
