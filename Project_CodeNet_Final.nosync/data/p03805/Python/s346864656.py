# ABC054 C One-stroke Path
N,M = map(int, input().split())

G = [[] for _ in range(N)]
reached = [False]*N

for _ in range(M):
    a,b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

cnt = 0

def DFS(x):

    global cnt
    global reached

    reached[x] = True
 
    if all(reached):
        cnt += 1
        reached[x] = False
 
        return

    for i in G[x]:
        if reached[i]:
            continue

        else:
            DFS(i)

    reached[x] = False

DFS(0)
print(cnt)