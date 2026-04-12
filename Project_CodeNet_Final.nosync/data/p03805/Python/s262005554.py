n,m = map(int,input().split())
edge = [[] for _ in range(n+1)]
for i in range(m):
    a,b = map(int,input().split())
    edge[a].append(b)
    edge[b].append(a)

def checkpath(nodes,E,current):
    next = []
    newnodes = nodes.copy()
    newnodes[current] = 0

    for e in E[current]:
        if newnodes[e]:
            next.append(e)

    if len(next) == 0:
        if sum(newnodes) == 0:
            return 1
        else:
            return 0
    else:
        return sum([checkpath(newnodes,E,e) for e in next])

nodes = [1]*(n+1)
nodes[0] = 0
print(checkpath(nodes,edge,1))