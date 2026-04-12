c=0
m=0
n=int(input())
a=input().split()
for i in range(n):
	if int(a[i])>=m:
		c+=1
		m=int(a[i])
print(c)