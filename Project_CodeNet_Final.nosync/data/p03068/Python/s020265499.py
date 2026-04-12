n = int(input())
s = input()
s = list(map(str, s))
k = int(input())
k -= 1

for i in range(n):
	if s[i] != s[k]:
		s[i] = '*'

print(''.join(s))