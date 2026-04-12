n,m=map(int,input().split())
l=[list(map(int,input().split())) for _ in range(m)]
p=[list() for i in range(n+1)]
for a,b in l:
	p[a].append(b)
	p[b].append(a)
q=[(1,[1])]
ans=0
while len(q)!=0:
	x,v=q.pop(0)
	if len(v)==n:
		ans+=1
		continue
	for i in p[x]:
		if i in v:continue
		q.append((i,v+[i]))
print(ans)
