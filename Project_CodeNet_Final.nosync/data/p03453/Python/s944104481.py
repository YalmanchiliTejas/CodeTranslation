import sys
from collections import deque, defaultdict
import heapq
input = sys.stdin.buffer.readline


def dijkstra(adj, start):
    # adj: [[to, cost] * vertices], 0th index must be empty
    dist = [float('inf')] * len(adj)
    dist[start] = 0
    q = []
    heapq.heappush(q, (0, start))
    while q:
        min_dist, v_from = heapq.heappop(q)
        if min_dist > dist[v_from]:
            continue
        v_tos = adj[v_from]
        for v_to, cost in v_tos:
            if min_dist + cost < dist[v_to]:
                dist[v_to] = min_dist + cost
                heapq.heappush(q, (dist[v_to], v_to))
    return dist


def main():
    mod = 10**9+7
    N, M = map(int, input().split())
    s, t = map(int, input().split())
    adj = [[] for _ in range(N+1)]
    for _ in range(M):
        l, r, d = map(int, input().split())
        adj[l].append((r, d))
        adj[r].append((l, d))

    dist = dijkstra(adj, s)
    collision_T = dist[t] / 2 if dist[t] % 2 == 1 else dist[t] // 2
    route = [0] * (N+1)
    route[t] = 1
    que = []
    heapq.heappush(que, (-dist[t], t))
    col_edge = set()
    seen = [0] * (N+1)
    seen[t] = 1
    while que:
        _, v = heapq.heappop(que)
        for u, d in adj[v]:
            if dist[v] == dist[u] + d:
                route[u] = (route[u] + route[v]) % mod
                if dist[u] < collision_T < dist[v]:
                    col_edge.add((u, v))
                elif dist[v] == collision_T:
                    col_edge.add((v, v))
                if not seen[u]:
                    heapq.heappush(que, (-dist[u], u))
                    seen[u] = 1

    #reverse
    route2 = [0] * (N+1)
    route2[s] = 1
    que = []
    heapq.heappush(que, (0, s))
    seen = [0] * (N+1)
    seen[s] = 1
    while que:
        _, v = heapq.heappop(que)
        for u, d in adj[v]:
            if dist[u] == dist[v] + d:
                route2[u] = (route2[u] + route2[v]) % mod
                if not seen[u]:
                    heapq.heappush(que, (dist[u], u))
                    seen[u] = 1

    #print(route)
    #print(route2)

    ans = pow(route[s], 2, mod)
    for u, v in col_edge:
        tmp = (route[v] * route2[u])%mod
        ans = (ans - pow(tmp, 2, mod))%mod
    print(ans)


if __name__=='__main__':
    main()
