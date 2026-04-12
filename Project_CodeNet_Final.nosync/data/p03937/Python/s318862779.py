import copy
from collections import deque
H,W = map(int,input().split())
A = []
for i in range(H):
    A.append(list(input()))
now = [0,0]
goal = [H-1,W-1]
x1 = [0,1]
y1 = [1,0]
alr = copy.deepcopy(A)
alr[0][0] = 1
que = deque()
que.append(now)
while que:
    q = que.popleft()
    for i in range(2):
        if 0 <= q[0]+x1[i] <= H-1 and 0 <= q[1]+y1[i] <= W-1 and alr[q[0]+x1[i]][q[1]+y1[i]] == '#':
            alr[q[0]+x1[i]][q[1]+y1[i]] = alr[q[0]][q[1]] +1
            que.append([q[0]+x1[i],q[1]+y1[i]])
if alr[-1][-1] != '#':
    num = alr[-1][-1]
    count = {}
    flag = True
    for i in range(1,num+1):
        count[i] = 0
    for i in range(H):
        for j in range(1,num+1):
            count[j] += alr[i].count(j)
        if '#' in alr[i]:
            flag = False
    
    for i,v in count.items():
        if v != 1:
            flag = False
    if flag:
        print('Possible')
    else:
        print('Impossible')
else:
    print('Impossible')