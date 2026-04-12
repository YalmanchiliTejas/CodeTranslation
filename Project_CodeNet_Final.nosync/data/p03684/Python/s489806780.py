#最小全域木　プリム法
n = int(input())
x = []
for i in range(0,n):
    X,Y = [int(_x) for _x in input().split()]
    x.append((i,X,Y))
x = sorted(x, key=lambda x:x[1])
y = sorted(x, key=lambda x:x[2])

g = [[] for _ in range(n)]
for j in range(1, len(x)):
    _i, _xx, _yy = x[j-1]
    i, xx, yy = x[j]
    dis1 = abs(_xx - xx)
    dis2 = abs(_yy - yy)
    g[i].append((dis1, _i))
    g[i].append((dis2, _i))
    g[_i].append((dis1, i))
    g[_i].append((dis2, i))

for j in range(1, len(y)):
    _i, _xx, _yy = y[j-1]
    i, xx, yy = y[j]
    dis1 = abs(_xx - xx)
    dis2 = abs(_yy - yy)
    g[i].append((dis1, _i))
    g[i].append((dis2, _i))
    g[_i].append((dis1, i))
    g[_i].append((dis2, i))

import heapq
def prim_heap():
    used = [True] * n #True:不使用
    edgelist = []
    for e in edge[0]:
        heapq.heappush(edgelist,e)
    used[0] = False
    res = 0
    while len(edgelist) != 0:
        minedge = heapq.heappop(edgelist)
        if not used[minedge[1]]:
            continue
        v = minedge[1]
        used[v] = False
        for e in edge[v]:
            if used[e[1]]:
                heapq.heappush(edgelist,e)
        res += minedge[0]
    return res

edge = g
print(prim_heap())