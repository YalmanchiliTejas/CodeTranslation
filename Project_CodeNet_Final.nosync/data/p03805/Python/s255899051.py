N,M = map(int,input().split())
G = [[]for i in range(N)]
for i in range(M):
    a,b = map(lambda x:int(x)-1,input().split())
    G[a].append(b)
    G[b].append(a)
ans = 0
H = [[0]]
while H:
    h = H.pop()
    if len(h)==N:
        ans+=1
        continue
    p = h[-1]
    for v in G[p]:
        if not(v in h):
            H.append(h+[v])
print(ans)