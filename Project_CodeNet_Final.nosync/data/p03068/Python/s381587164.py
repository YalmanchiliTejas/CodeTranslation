n = input()
str = input()
v = int(input()) - 1

ans = ""

for i in str:
	if i == str[v]:
		ans += i
	else:
		ans += "*"

print(ans)