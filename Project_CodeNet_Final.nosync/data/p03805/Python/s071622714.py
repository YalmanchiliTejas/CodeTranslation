#!/usr/bin/env python3
from collections import deque

N, M = map(int, input().split())
adj = [[] for _ in range(N)]
for i in range(M):
    a, b = map(lambda x: int(x)-1, input().split())
    adj[a].append(b)
    adj[b].append(a)

def DFS(now, visited):
    if len(visited) == N:
        return 1
    else:
        count = 0
        for u in adj[now]:
            if u not in visited:
                count += DFS(u, visited+[u])
        return count


def main():
    queue = deque([0])
    visited = [0]
    ans = DFS(0, visited)
    print(ans)


if __name__ == "__main__":
    main()
