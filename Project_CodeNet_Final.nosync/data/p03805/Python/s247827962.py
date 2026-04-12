import math as mt
import sys, string
from collections import Counter, defaultdict
input = sys.stdin.readline

# input functions
I = lambda : int(input())
M = lambda : map(int, input().split())
ARR = lambda: list(map(int, input().split()))

ans = 0
def dfs(u, graph, visited, curr_len, req_len):
    global ans
    if visited[u]:
        return
    visited[u] = 1
    if curr_len == req_len:
        ans += 1
        visited[u] = 0
        return
    for kid in graph[u]:
        dfs(kid, graph, visited, curr_len+1, req_len)
    visited[u] = 0

def main():
    global ans
    n, m = M()
    graph = defaultdict(list)
    for _ in range(m):
        u, v = M()
        graph[u].append(v)
        graph[v].append(u)
    visited = [0 for _ in range(n+1)]
    dfs(1, graph, visited, 0, n - 1)
    print(ans)

tc = 1
# tc = I()
for _ in range(tc):
    main()