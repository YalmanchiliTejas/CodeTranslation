from heapq import *

def prim(V, E):
    '''
    Input:
        V = list(range(N))
        E = {i: defaultdict(int) for i in range(N)}
    Output:
        the edges of the minimum weight tree and its weight
    '''
    N = len(V)
    weight = 0; edges = [];
    used = [False]*N; used[0] = True; n_used = 1;
    heap = [(c, 0, v) for v, c in E[0].items()]; heapify(heap)
    while heap and n_used < N:
        c, u, v = heappop(heap)
        if used[v]: continue
        used[v] = True; n_used += 1; edges.append((u, v))
        weight += c
        for w, d in E[v].items():
            if not used[w]: heappush(heap, (d, v, w))
    return edges, weight

N = int(input())
cities = [(a, b, i) for i, (a, b) in enumerate([tuple(map(int, input().split())) for _ in range(N)])]
sorted_x, sorted_y = sorted(cities, key=lambda x:x[0]), sorted(cities, key=lambda x:x[1])
E = {i: {} for i in range(N)}
for i in range(N-1):
    (a1, _, u), (a2, _, v) = sorted_x[i], sorted_x[i+1]
    E[u][v] = min(a2 - a1, E[u][v]) if E[u].get(v) is not None else a2 - a1
    E[v][u] = E[u][v]
    (_, b1, u), (_, b2, v) = sorted_y[i], sorted_y[i+1]
    E[u][v] = min(b2 - b1, E[u][v]) if E[u].get(v) is not None else b2 - b1
    E[v][u] = E[u][v]
V = list(range(N))
_, ans = prim(V, E)
print(ans)