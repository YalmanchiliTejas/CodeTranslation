inpl = lambda: list(map(int,input().split()))

def routes(start, tovisit):
	if len(tovisit) == 0:
		return 1
	else:
		ret = sum(routes(nextnode, tovisit - {nextnode}) for nextnode in neigh[start] & tovisit)
		if ret is None:
			return 0
		else:
			return ret

N, M = inpl()
neigh = [ set() for _ in range(N) ]
for _ in range(M):
	a, b = inpl()
	neigh[a-1].add(b-1)
	neigh[b-1].add(a-1)

print(routes(0,set(range(1,N))))