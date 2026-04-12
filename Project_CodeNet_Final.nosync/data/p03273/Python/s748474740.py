h,m = map(int,input().split())

a = []

for i in range(h):
	b = input()
	if b.count('.') != m:
		a.append(b)

b = len(a)
c =['' for i in range(m)]

for i in a:
	for j in range(m):
		c[j] += i[j]
d = []
for i in c:
	if i.count('.') != len(i):
		d.append(i)

b = len(d)
c =['' for i in range(len(d[0]))]

for i in d:
	for j in range(len(d[0])):
		c[j] += i[j]

for i in c:
	print(i)
