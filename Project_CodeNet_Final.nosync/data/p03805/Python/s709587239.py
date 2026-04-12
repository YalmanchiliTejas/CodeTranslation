#!/usr/bin/python3

import sys

sys.setrecursionlimit(10000)
ans = 0

def dfs(cur, visited, G):
    visited[cur] = True

    if all(visited):
        global ans
        ans += 1

    for c in G[cur]:
        if not visited[c]:
            dfs(c, visited, G)
            visited[c] = False
    return


def main():
    n, m = map(int, input().split())
    G = [[] for _ in range(n) ]

    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1; b -= 1;
        G[a] += [b]
        G[b] += [a]

    v = [ False for _ in range(n) ]

    dfs(0, v, G)
    print(ans)

main()