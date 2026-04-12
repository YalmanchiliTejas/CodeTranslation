n=int(input())
s=list(str(input()))
k=int(input())

for i in range(len(s)):
	if s[i]!=s[k-1]:
		s[i]='*'
for i in range(len(s)):
	if i==len(s):
		print(s[i])
	else:
		print(s[i],end='')