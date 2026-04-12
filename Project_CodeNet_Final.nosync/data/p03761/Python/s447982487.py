n=int(input())
S=[list(input()) for i in range(n)]
co=set(S[0])
for x in S:
	co=co&set(x)
if len(co)==0:
	print('')
	exit(0)
dic={x:50 for x in co}
for s in S:
	for x in co:
		dic[x]=min(dic[x],s.count(x))
ans=[]
c=sorted(co)
for x in c:
	for i in range(dic[x]):
		ans.append(x)
print(''.join(ans))

	

