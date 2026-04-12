import itertools
import collections
N,M=map(int,raw_input().split())
#print N,M
a=[map(int,raw_input().split()) for i in range(M)]
#print a
b=list(itertools.permutations(range(1,N+1)))
#print b

ans=0
for i in b:
	if i[0]!=1:
		continue
	c=[]
	for j in i:
		#print i,j
		if len(c)<2:
			c.append(j)

		if len(c)==2:
			if c in a or c[::-1] in a:
				cnt=1
			else:
				cnt=0
				break
			c.pop(0)
	ans+=cnt
print ans