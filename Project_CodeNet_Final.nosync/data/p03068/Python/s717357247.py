n = int(input())
s = input()
k = int(input())

obj = s[k-1]

ans = ""

for i in range(n):
	if s[i] == obj:
		ans += obj
	else:
		ans += "*"

print(ans)