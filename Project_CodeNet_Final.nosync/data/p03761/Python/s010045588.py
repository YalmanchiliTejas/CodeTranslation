from  collections import Counter
n = int(input())
s = [input() for i in range(n)]

c =Counter(list(s[0]))
for i in s:
	a = list(i)
	c &= Counter(a)
b = ""
for j,k in sorted(c.items()):
	b += j*k
print (b)