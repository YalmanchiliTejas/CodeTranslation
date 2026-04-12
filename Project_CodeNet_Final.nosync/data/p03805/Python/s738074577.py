N, M = map(int, input().split())
Bs = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    Bs[a].append(b)
    Bs[b].append(a)
import heapq
import copy

st = []
ap = [{1: True}]
heapq.heappush(st, (1, 0))
c = 0
while len(st) > 0:
    (node, log) = heapq.heappop(st)
    for b in Bs[node]:
        if b in ap[log]:
            continue
        elif len(ap[log]) == N - 1:
            c += 1
        else:
            heapq.heappush(st, (b, len(ap)))
            newlog = copy.copy(ap[log])
            newlog[b] = True
            ap.append(newlog)
print(c)