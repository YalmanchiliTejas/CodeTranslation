n,m=map(int,raw_input().split())
graph=[[] for i in xrange(n)]
while m>0:
	m-=1
	a,b=map(int,raw_input().split())
	a-=1
	b-=1
	graph[a].append(b)
	graph[b].append(a)
# print graph
pathcount=0

def dfs(source,l=[]):
	global pathcount
	for i in (graph[source]):
		# print source,graph[source]
		if i not in l:
			l.append(source)
			if len(l)==n:
				pathcount+=1
			# print "exploring ",source," to ",i
			dfs(i,l)
			l.remove(source)
			# print "completed ",source
		# else:
			# print i,"is alrready explored"
	

			
dfs(0,[0])
print pathcount