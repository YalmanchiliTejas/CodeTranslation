from collections import deque
N,M = map(int,input().split())
g = [[] for i in range(N)]
for i in range(M):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)
ans = 0
que = deque([[0]])
while len(que) != 0:
    p = que.popleft()
    if len(p) == N:
        ans += 1
    else:
        for i in range(len(g[p[-1]])):
            if not g[p[-1]][i] in p:
                que.append(p + [g[p[-1]][i]])
print(ans)
