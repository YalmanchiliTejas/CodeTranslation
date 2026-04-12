N, M = map(int, input().split())
edges = [[] for _ in range(N + 1)]
res = 0
passed_nodes = set()

for _ in range(M):
    a, b = map(int, input().split())
    edges[a].append(b)
    edges[b].append(a)

def recur(i, tot, pns):
    global res
    pns = pns.copy()

    if tot == N:
        res += 1
        return

    flag = False
    pns.add(i)

    for e in edges[i]:
        if e not in pns:
            recur(e, tot + 1, pns)
            flag = True

    if not flag:
        return

recur(1, 1, passed_nodes.copy())

print(res)

