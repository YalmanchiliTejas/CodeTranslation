#!/usr/bin/env python3
from collections import deque

N, M = map(int, input().split())
adj = [[] for _ in range(N)]
for i in range(M):
    a, b = map(lambda  x: int(x)-1, input().split())
    adj[a].append(b)
    adj[b].append(a)

ans = 0

def DFS(now,visited):
    global ans
    if len(visited) == N:
        ans += 1
    else:
        for u in adj[now]:
            if u not in visited:
                DFS(u,visited+[u])

def main():
    queue = deque([0])
    visited = [0]
    DFS(0,visited)
    print(ans)

if __name__ == "__main__":
    main()
