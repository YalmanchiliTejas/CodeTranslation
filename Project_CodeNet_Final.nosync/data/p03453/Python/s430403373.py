import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
from heapq import *

"""
とりあえず何通りあるかを数える：各頂点を通る時点での場合の数
最後に衝突する方法を除外する：頂点での衝突、辺での衝突
辺での衝突：距離を見れば分かる
"""

MOD = 10 ** 9 + 7

N,M = map(int,input().split())
S,T = map(int,input().split())
graph = [[] for _ in range(N+1)]
for _ in range(M):
    u,v,d = map(int,input().split())
    graph[u].append((v,d))
    graph[v].append((u,d))

def dijkstra(S):
    # 距離、パスの個数を返す
    INF = 10 ** 15
    dist = [INF] * (N+1)
    cnt_path = [0] * (N+1)
    cnt_path[S] = 1
    q = [(0,S)] # 距離、場所
    while q:
        d,x = heappop(q)
        if dist[x] < d:
            continue
        dist[x] = d
        for y,dy in graph[x]:
            if d + dy > dist[y]:
                continue
            if d + dy == dist[y]:
                cnt_path[y] += cnt_path[x]
                continue
            cnt_path[y] = cnt_path[x]
            dist[y] = d + dy
            heappush(q,(d+dy,y))
    return dist, cnt_path

dist_S, cnt_path_S = dijkstra(S)
dist_T, cnt_path_T = dijkstra(T)

D = dist_S[T]
# 最短路の組
answer = cnt_path_S[T] * cnt_path_T[S]
# 頂点での衝突
for x in range(1,N+1):
    if dist_S[x] == dist_T[x]:
        t = cnt_path_S[x] * cnt_path_T[x] % MOD
        answer -= t * t % MOD
# 辺での衝突。S側がx、T側がy
for x in range(1,N+1):
    for y,d in graph[x]:
        dx = dist_S[x]
        dy = dist_T[y]
        if dx + dy + d == D and dx + d > dy and dy + d > dx:
            t = cnt_path_S[x] * cnt_path_T[y] % MOD
            answer -= t * t % MOD

answer %= MOD
print(answer)

