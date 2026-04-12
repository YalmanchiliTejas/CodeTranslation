s = input()
n = len(s)

for i in range(n - 1):
	if s[i:i + 2] == 'AC':
		print('Yes')
		break
	elif i == n - 2:
		print('No')