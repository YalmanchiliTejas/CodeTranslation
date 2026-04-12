n = int(input())
s = input()
k = int(input())
ans = ""
for i in s :
	if i == s[k-1] :
		ans += s[k-1]
	else :
		ans += "*"
print (ans)