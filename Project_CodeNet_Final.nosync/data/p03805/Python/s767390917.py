# -*- coding: utf-8 -*-
from queue import Queue

q = Queue()
N, M = [int(n) for n in input().split()]
graph = {n:[] for n in range(1, N+1)}

for m in range(M):
    a, b = [int(n) for n in input().split()]
    graph[a].append(b)
    graph[b].append(a)

end = 0
for n in range(2, N+1):
    if len(graph[n]) == 1:
        end = n

ok = []
q.put([1, []])

while not q.empty():
    point, past = q.get()
    for d in graph[point]:
        if not d in past:
            if len(past + [point, d]) == N:
                ok.append(past + [point, d])
            else:
                q.put([d, past+[point]])

print(len(ok))            