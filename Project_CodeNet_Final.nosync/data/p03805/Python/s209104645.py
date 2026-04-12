from collections import deque
N,M = map(int,input().split())
T = [[] for i in range(N+1)]
for i in range(M):
    a,b = map(int,input().split())
    T[a].append(b)
    T[b].append(a)
Q = deque([(1,[1])])
ans = 0
while Q:
    p,V = Q.pop()
    if len(V)==N:
        ans += 1
        continue
    for c in T[p]:
        if not(c in V):
            Q.append((c,V+[c]))
print(ans)