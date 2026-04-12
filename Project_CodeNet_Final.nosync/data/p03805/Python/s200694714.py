import itertools

n,m=map(int,input().split())
linelist=[list(map(int,input().split())) for i in range(m)]

numlist=[i for i in range(1,n+1)]

plist=list(itertools.permutations(numlist))

sum=0

for challenger in plist:
	if challenger[0] != 1:
		pass
	else:
		needlist=[]
		for i in range(n-1):
			tmp=[]
			tmp.extend([challenger[i],challenger[i+1]])
			tmp.sort()
			needlist.append(tmp)
		addflag=True
		for need in needlist:
			if not need in linelist:
				addflag = False
		
		if addflag:
			sum+=1

print(sum)
