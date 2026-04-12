n=int(input())
h=list(map(int,input().split()))

c=0
b=0
for i in h:
	if i >= b:
		c+=1
		b=i
print(c)