n = int(input())
s = list(input())
k = int(input())

s2 = ""
c = s[k-1]
for i in range(len(s)):
	if s[i] == c:
		s2 += c
	else:
		s2 += "*"
print(s2)