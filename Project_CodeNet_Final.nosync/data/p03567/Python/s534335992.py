x=input()
x=list(x)
t=0
for i in range(len(x)-1):
	if x[i]=='A' and x[i+1]=='C':
		print('Yes')
		t=1
		break
if t==0:
	print('No')