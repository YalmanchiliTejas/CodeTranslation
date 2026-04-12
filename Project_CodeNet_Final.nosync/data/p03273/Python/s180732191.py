a = input().split()
h = int(a[0])
w = int(a[1])

m = []
for i in range(h):
	sb = input()
	if not  sb == '.'*w:
		m.append(sb)
			
if not m == []:
	output = [[] for i in range(len(m))]
	for i in range(len(m[0])):
		notok = True
		for j in range(len(m)):
			notok = notok and (m[j][i] == '.')
			if notok == False:
				break
		if notok == False:
			for j in range(len(m)):
				output[j].append(m[j][i])
				
for i in range(len(output)):
	print(''.join(output[i]))
	
