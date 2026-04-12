from collections import deque
import copy
n,m = map(int,input().split())
Map = [[] for i in range(n)]

for i in range(m):
    a,b = map(int,input().split())
    Map[a-1].append(b-1)
    Map[b-1].append(a-1)
visit = [False for i in range(n)]
ans = 0
q = deque()
q.append((0,visit))
while q:
    index,visit = q.popleft()
    Visit = copy.deepcopy(visit)
    if not Visit[index]:
        Visit[index] = True
    else:
        continue
    if all(Visit):
        ans += 1
        continue
    for i in Map[index]:
        q.append((i,Visit))
print(ans)