n = input()
n = int(n)
l=[i for i in map(int,input().split())]
maximum=l[0]
c=0
for i in range(n):
	if(l[i]>=maximum):
		maximum=l[i]
		c=c+1
print(c)