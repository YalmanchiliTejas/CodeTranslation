n = int(input())
a = list(map(int, input().split()))
b_1 = []
b_2 = []
b = []
for i in reversed(range(len(a))):
	if i % 2 != 0:
		b_1.append(a[i])
	else:
		b_2.append(a[i])
if len(a) % 2 == 0:
	b_2.reverse()
	b.extend(b_1)
	b.extend(b_2)
else:
	b_1.reverse()
	b.extend(b_2)
	b.extend(b_1)
for b_num in b:
	print(b_num, end = ' ')