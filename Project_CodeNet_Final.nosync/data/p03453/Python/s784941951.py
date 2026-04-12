import heapq
import sys
input = sys.stdin.buffer.readline

def dijkstra(start: int, graph: list) -> list:
    """dijkstra法: 始点startから各頂点への最短距離を求める
    計算量: O((E+V)logV)
    """
    INF = 10 ** 18
    MOD = 10 ** 9 + 7
    n = len(graph)
    dist = [INF] * n
    ptn = [0] * n 
    dist[start] = 0
    ptn[start] = 1 
    q = [(0, start)] # q = [(startからの距離, 現在地)]
    while q:
        d, v = heapq.heappop(q)
        if dist[v] < d:
            continue
        for nxt_v, cost in graph[v]:
            if dist[v] + cost == dist[nxt_v]:
                ptn[nxt_v] += ptn[v]
                ptn[nxt_v] %= MOD
            if dist[v] + cost < dist[nxt_v]:
                dist[nxt_v] = dist[v] + cost
                ptn[nxt_v] = ptn[v]
                ptn[nxt_v] %= MOD
                heapq.heappush(q, (dist[nxt_v], nxt_v))
    return dist, ptn




n, m = list(map(int, input().split()))
s, t = list(map(int, input().split()))
info = [list(map(int, input().split())) for i in range(m)]
MOD = 10 ** 9 + 7

s -= 1
t -= 1
graph = [[] for i in range(n)]
for a, b, cost in info:
    a -= 1
    b -= 1
    graph[a].append((b, cost))
    graph[b].append((a, cost))
    
dist_st, ptn_st = dijkstra(s, graph)
dist_ts, ptn_ts = dijkstra(t, graph)

min_cost, max_ptn = dist_st[t], ptn_st[t]
all_ptn = (max_ptn * max_ptn) % MOD

# 最短路で使用する頂点を復元
use = [False] * n
use[t] = True
stack = [t]
while stack:
    v = stack.pop()
    for prv_v, cost in graph[v]:
        if use[prv_v]:
            continue
        if dist_st[v] == dist_st[prv_v] + cost:
            use[prv_v] = True
            stack.append(prv_v)

# 頂点上で出会うとき
for i in range(n):
    if dist_st[i] == dist_ts[i] and use[i]:
        all_ptn -= (ptn_st[i] * ptn_ts[i]) ** 2
        all_ptn %= MOD
        
# 辺上で出会うとき
for a, b, cost in info:
    a -= 1
    b -= 1
    if abs(dist_st[a] - dist_st[b]) != cost:
        continue
    if (not use[a]) or (not use[b]):
        continue
    if dist_st[a] > dist_st[b]:    
        a, b = b, a
    if dist_st[a] < dist_ts[a] and dist_st[b] > dist_ts[b]:
        all_ptn -= (ptn_st[a] * ptn_ts[b]) ** 2
    all_ptn %= MOD
print(all_ptn)