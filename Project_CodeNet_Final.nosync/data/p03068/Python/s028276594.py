n=int(input())
s=list(input())
k=int(input())
x=s[k-1]
for i in range(n):
	if s[i]!=x:
		s[i]='*'
for i in range(n):
	print(s[i] ,end='')