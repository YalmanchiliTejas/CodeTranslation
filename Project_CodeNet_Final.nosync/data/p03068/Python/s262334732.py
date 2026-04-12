n = int(input())
s =list(input())
k = int(input())

chk = s[k-1]
for i in range(len(s)):
	if(s[i] != chk):
		s[i] = "*"
	print(s[i],end="")
print("")
