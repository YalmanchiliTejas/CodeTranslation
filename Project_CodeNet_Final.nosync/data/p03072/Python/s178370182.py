N=int(input())
H=[int(i) for i in input().split()]
c=0
l=0
for i in H:
	if i>=l:
		c+=1
		l=i
print(c)