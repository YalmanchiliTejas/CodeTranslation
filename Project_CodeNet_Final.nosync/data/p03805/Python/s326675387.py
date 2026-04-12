import itertools
n,m = (int(i) for i in input().split())
a = [[int(i) for i in input().split()] for i in range(m)]
b,c,answer = [],[],0
for i in range(2,n+1):
	c.append(i)
for i in range(n):
	x = []
	for j in a:
		if j[0]==i+1:
			x.append(j[1])
		elif j[1]==i+1:
			x.append(j[0])
	b.append(x)
for i in list(itertools.permutations(c,n-1)):
	if i[0] in b[0] and all(i[j+1] in b[i[j]-1] for j in range(n-2)):
		answer += 1
print(answer)