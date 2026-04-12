n, m = map(int, input().split())
link = [[] for _ in range(n)]
for i in range(m):
    tmp = list(map(int,input().split()))
    link[tmp[0]-1].append(tmp[1]-1)
    link[tmp[1]-1].append(tmp[0]-1)

from collections import deque
Q = deque()
Q.append([0,[0]]) # now, history

import copy
ans=0
while Q:
    now,org_hist = Q.popleft()

    for nxt in link[now]:
        if nxt in org_hist:
            continue
        hist = copy.copy(org_hist)

        hist.append(nxt)
        if len(hist) >= n:
            ans+=1
        else:
            Q.append([nxt,hist])
print(ans)