n=int(input())
s=list(input())
k=int(input())
x=s[k-1]
for i in range(n):
	if s[i]!=x:
		s[i]='*'
	print(s[i] ,end='')