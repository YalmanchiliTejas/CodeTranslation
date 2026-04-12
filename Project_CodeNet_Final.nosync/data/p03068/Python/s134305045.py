N = int(input())
s = input()
ans= ' '
k = int(input())
const = s[k-1]
for x in s:
	if x == const:
		ans += x
	else:
		ans += '*'
print(ans)