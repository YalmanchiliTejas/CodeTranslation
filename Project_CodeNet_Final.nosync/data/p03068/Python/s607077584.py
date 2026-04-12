n=int(input())
s=input()
k=int(input())
d=""
for i in range(n):
	if s[i]==s[k-1]:
		d+=s[i]
	else:
		d+="*"
print(d)