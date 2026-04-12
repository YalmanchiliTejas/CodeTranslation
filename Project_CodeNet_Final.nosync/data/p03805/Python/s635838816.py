from itertools import permutations
n, m = map(int,input().split())
dist =[[0 for i in range(n)] for j in range(n)]

for i in range(m):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    dist[a][b] = 1
    dist[b][a] = 1
ans = 0
for p in permutations([i for i in range(1,n)]):
    t = True
    for i in range(n-2):
        if i == 0:
            if dist[0][p[0]] == 0:
                t = False
                break
        if dist[p[i]][p[i+1]] == 0:
            t = False
            break
    if t:
        ans += 1
        #print(p)

print(ans)