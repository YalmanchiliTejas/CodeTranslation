import sys
import heapq as hq

mod = 10**9 + 7

readline = sys.stdin.buffer.readline

ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))

def dijkstra(G, s, t=None):
    dist = [-1]*len(G)
    fr = [0]*len(G)
    dist[s] = 0
    fr[s] = 1
    q = [(0, s)]
    while q:
        d, v = hq.heappop(q)
        if d > dist[v]: continue
        for x, c in G[v]:
            if dist[x] < 0 or dist[x] > d + c:
                dist[x] = d + c
                fr[x] = fr[v]
                hq.heappush(q, (d + c, x))
            elif dist[x] == d + c:
                fr[x] = (fr[x] + fr[v]) % mod
    return dist, fr


def solve():
  n, m = nm()
  s, t = nm()
  s -= 1; t -= 1
  G = [list() for _ in range(n)]
  for _ in range(m):
    u, v, d = nm()
    u -= 1; v -= 1
    G[u].append((v, d))
    G[v].append((u, d))
  diss, frs = dijkstra(G, s)
  dist, frt = dijkstra(G, t)
  cnt = frt[s] * frs[t] % mod
  for i in range(n):
    if diss[i] + dist[i] == dist[s] and diss[i] == dist[i]:
      # print(i)
      cnt = (cnt - (frs[i] * frt[i] % mod)**2 % mod) % mod
    for j, x in G[i]:
      if diss[i] + x + dist[j] == dist[s] and diss[i] < dist[i] and diss[j] > dist[j]:
        # print(i, j, (diss[i], diss[j]), (dist[i], dist[j]))
        cnt = (cnt - (frs[i] * frt[j] % mod)**2 % mod) % mod
  print(cnt)
  return

solve()
