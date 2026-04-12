s=list(input())
a=0
for i in range(3):
	if s[i]=='A':
		a+=1
if a==0 or a==3:
	print('No')
else:
	print('Yes')
