n,*a=map(int,open(0).read().split())
ans=0
while True:
	div=[x//n for x in a]
	ps=sum(div)
	ans+=ps
	if not ps:
		break
	a=[x-(n+1)*d+ps for x,d in zip(a,div)]
print(ans)