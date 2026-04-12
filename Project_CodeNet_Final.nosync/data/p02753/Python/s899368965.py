i=input()
j=i[0]
k=0

for n in range(2):
	if i[n+1]!=i[0]:
		k=1
if k==0:
	print('No')
else:
	print('Yes')