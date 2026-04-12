import string

n = int(input())
s = input()
k = int(input())

remain = s[k-1]

for char in string.ascii_lowercase:
	if char == remain:
		continue
	else:
		s = s.replace(char, '*')
		
print(s)