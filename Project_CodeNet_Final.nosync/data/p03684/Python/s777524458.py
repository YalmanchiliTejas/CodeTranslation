#!/usr/bin/env python3

import heapq

def main():
    n = int(input())
    nodes = []
    for i in range(n):
        xi, yi = map(int, input().split())
        nodes.append((i, xi, yi))

    adj = [[] for i in range(n)]
    nodesx = sorted(nodes, key=(lambda x: x[1]))
    for j in range(n - 1):
        i1 = nodesx[j][0]
        i2 = nodesx[j + 1][0]
        adj[i1].append(i2)
        adj[i2].append(i1)
    nodesy = sorted(nodes, key=(lambda x: x[2]))
    for j in range(n - 1):
        i1 = nodesy[j][0]
        i2 = nodesy[j + 1][0]
        adj[i1].append(i2)
        adj[i2].append(i1)

    res = 0
    q = [(0, 0)]
    visited = [False for i in range(n)]
    while q:
        d, i = heapq.heappop(q)
        if visited[i]:
            continue
        visited[i] = True
        res += d
        for j in adj[i]:
            if visited[j]:
                continue
            heapq.heappush(q, (dist(i, j, nodes), j))
    print(res)

def dist(i, j, nodes):
    _, xi, yi = nodes[i]
    _, xj, yj = nodes[j]
    res = min(abs(xi - xj), abs(yi - yj))
    return res

if __name__ == "__main__":
    main()
