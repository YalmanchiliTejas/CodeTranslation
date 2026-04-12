N, M = map(int,input().split())

to = [[] for i in range(N)]
for i in range(M):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    to[a].append(b)
    to[b].append(a)
cnt = 0
def search(i,visited):
    global cnt
    if len(visited) == N:
        cnt += 1
    for v in to[i]:
        if v not in visited:
            search(v,visited+[v])
search(0,[0])
print(cnt)