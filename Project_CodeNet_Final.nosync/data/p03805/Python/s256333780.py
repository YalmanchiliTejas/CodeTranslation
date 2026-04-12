N, M = map(int, input().split())
edges = [input().split() for i in range(M)]
searched_edge = [0 for i in range(M)]
searched = [0 for i in range(N)]
stack = ['1']

count = 0
searched[0] = 1
def search(stack, searched, edges, searched_edge):
	global count
	
	while (stack):
		now = stack.pop()
		searched[int(now)-1] = 1
		
		if 0 not in searched:
			count += 1
			return
		
		for edge in edges:
			if now in edge:
				next = edge[1] if edge[0] == now else edge[0]
				searched_edge[edges.index(edge)] = 1
				if searched[int(next)-1] == 0:
					stack += [next]
					searched[int(next)-1] = 1
					search(stack, searched, edges, searched_edge)
					searched_edge[edges.index(edge)] = 0
					searched[int(next)-1] = 0

	return

search(stack, searched, edges, searched_edge)
print(count)