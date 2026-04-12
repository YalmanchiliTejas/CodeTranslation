n = int(input())
s = input()
k = int(input())
ss = ''
for i in range(n):
	if s[i] == s[k-1]:
		ss += s[i]
	else:
		ss += '*'
print(ss)