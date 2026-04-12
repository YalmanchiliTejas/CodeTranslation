from itertools import permutations
n,m = map(int,input().split())
edge = [[0]*n for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    a-=1; b-=1
    edge[a][b] = edge[b][a] = 1
ret = 0
for i in permutations(range(n)):
    if i[0] != 0 : break
    for j in range(n-1):
        if edge[i[j]][i[j+1]] == 0: break
    else:
        ret += 1
print(ret)
