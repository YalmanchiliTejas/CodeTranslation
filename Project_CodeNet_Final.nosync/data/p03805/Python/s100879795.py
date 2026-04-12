import itertools
N,M=map(int,input().split())
edges=[]
for i in range(M):
    edges.append(list(map(int,input().split())))

res=0
for i in itertools.permutations(range(2,N+1),N-1):
    path=[1]+list(i)
    check=[sorted(path[i:i+2]) in edges for i in range(len(path)-1)]
    if not False in check:
        res+=1
print(res)