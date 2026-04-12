n = input()
s = list(input())
k = int(input())

target = s[k-1]

ans = ""

for ss in s:
	if(ss == target):
		ans += ss
	else:
		ans += "*"
print(ans)