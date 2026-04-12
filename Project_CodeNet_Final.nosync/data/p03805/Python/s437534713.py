N,M = map(int,input().split(" "))
G = [[] for x in range(N)]
E = [0]*N
for i in range(M):
    a,b = map(int,input().split(" "))
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

def search(x):
    a = 0
    E[x] = 1
    if 0 not in E:
        a += 1
    for g in G[x]:
        if E[g] == 0:
            a += search(g)
    E[x] = 0
    return a

print(search(0))