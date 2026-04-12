from collections import deque
N, M = map(int, input().split(' '))
neib = {}
for i in range(M):
    a, b = map(int, input().split(' '))
    if not a in neib.keys():
        neib[a] = [b]
    else:
        neib[a].append(b)
    if not b in neib.keys():
        neib[b] = [a]
    else:
        neib[b].append(a)

q = deque([])
q.append([1])
res = 0
while len(q) > 0:
    p = q.pop()
    if set(p) == set([i for i in range(1, N+1)]):
        res += 1
    cand = neib[p[-1]]
    for n in cand:
        if not n in p:
            q.append(p + [n])

print(res)