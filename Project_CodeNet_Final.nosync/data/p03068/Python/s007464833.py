n = int(input())
s = input()
k = int(input())

moji = s[k - 1]

ans = ''

for i in range(n):
	if s[i] == moji:
		ans += s[i]
	else:
		ans += '*'

print(ans)