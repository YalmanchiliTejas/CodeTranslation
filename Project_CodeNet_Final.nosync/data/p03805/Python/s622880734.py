n,m=[int(x) for x in input().split()]
edges=[[] for x in range(n)]
for i in range(m):
    a,b=[int(x)-1 for x in input().split()]
    edges[a].append(b)
    edges[b].append(a)
def ans(path):
    if len(path)==n:
        # print([x+1 for x in path])
        return 1
    res=0
    for i in range(n):
        if not i in path and  i in edges[path[-1]]:
            res+=ans(path+[i])
    return res
print(ans([0]))