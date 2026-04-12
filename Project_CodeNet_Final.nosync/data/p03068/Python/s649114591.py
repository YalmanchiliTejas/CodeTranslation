
n = int(input())
s = input()
k = int(input())

p = s[k-1]
out = ""
for c in s:
	if(c == p):
		out += c
	else:
		out += "*"

print(out)