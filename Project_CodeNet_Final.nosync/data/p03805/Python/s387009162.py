import sys
input = sys.stdin.readline
N, M = map(int,input().split())
edge_from = [[] for _ in range(N)]
for i in range(M):
    a, b = map(int,input().split())
    a -= 1
    b -= 1
    edge_from[a].append(b)
    edge_from[b].append(a)

def rec(v, visited):
    if len(visited) == N:
        return 1
    ret = 0
    for nxt in edge_from[v]:
        if nxt not in visited:
            ret += rec(nxt, [x for x in visited]+[nxt])
    return ret
print(rec(0, [0]))