from collections import Counter
n = int(input())
alp = "abcdefghijklmnopqrstuvwxyz"
dic = {}
e = set()
for i in range(n):
	s = input()
	c = Counter(list(s))
	d = c.keys()
	e = e & d
	if i == 0:
		for j in c.keys():
			dic[j] = c[j]
			e.add(j)
	else:
		for j in c.keys():
			if j in dic:
				dic[j] = min(dic[j],c[j])
s = ""
sor = sorted(dic)
for i in sor:
	if i in e:
		b = i * dic[i]
		s += b
print (s)