n = int(input())
s = [i for i in input()]
k = int(input())
g = s[k-1]

for i in range(n):
	if s[i] != g:
		s[i] = "*"

print("".join(s))
