from sys import stdin
import itertools 
N,M = [int(x) for x in stdin.readline().rstrip().split()]

edges = []
for m in range(M):
    a,b = [int(x) for x in stdin.readline().rstrip().split()]
    edges.append((a,b))
    edges.append((b,a))
    
node = list(range(1,N+1))

ans = 0
for i in itertools.permutations(node):
    f = True
    for j in range(len(i)-1):
        if (not (i[j],i[j+1]) in edges):
            f = False
    if f and i[0] == 1:
        ans += 1
print(ans)