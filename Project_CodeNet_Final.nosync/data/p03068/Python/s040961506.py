n = int(input())
s = input()
k = int(input())

a = s[k - 1]
for i in s:
	if i != a:
		s = s.replace(i, '*')

print(s)