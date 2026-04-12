n,x,m=map(int,input().split())
ans=x
totol=n
was=[0]*m
was[x]=1
cs=x
cr=1
n-=1
seq=[x]
while n>0:
	cs=cs*cs%m
	seq.append(cs)
	cr+=1
	n-=1
	if was[cs]:
		if cs<=1:exit(print(ans+cs*(n+1)))
		res=sum(seq[:was[cs]-1])
		totol-=was[cs]-1
		loop=cr-was[cs]
		sumonloop=sum(seq[was[cs]:cr])
		res+=totol//loop*sumonloop
		for i in range(totol%loop):
			res+=cs
			cs=cs*cs%m
		exit(print(res))
	else:was[cs]=cr
	ans+=cs
print(ans)
'''
492443256176507
9 2 7

26

'''