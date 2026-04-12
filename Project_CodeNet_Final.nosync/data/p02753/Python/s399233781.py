s = input()
r = 'Yes'
for c in s:
	if s.count(c) == 3:
		r = 'No'
		break
print(r)