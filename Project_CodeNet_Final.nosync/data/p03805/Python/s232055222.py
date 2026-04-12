from collections import deque
import numpy as np
import math
import copy
import bisect  # index = bisect.bisect_left(list,num)

N, M = map(int, input().split())
E = [[] for i in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    E[a - 1].append(b - 1)
    E[b - 1].append(a - 1)


q = deque()
ans = 0
visited = [False for i in range(N)]
visited[0] = True
q.append((0, visited))
while(len(q) > 0):
    #print("q:", q)
    tmp, visited = q.popleft()
    if not(False in visited):
        ans += 1
    for e in E[tmp]:
        if not visited[e]:
            tmp_visited = copy.deepcopy(visited)
            tmp_visited[e] = True
            #print(e, tmp_visited)
            q.append((e, copy.deepcopy(tmp_visited)))

print(ans)