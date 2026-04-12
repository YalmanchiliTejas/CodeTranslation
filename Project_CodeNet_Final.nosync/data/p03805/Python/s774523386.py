import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

from itertools import permutations

n, m = map(int, readline().split())
graph = [[] for _ in range(n + 1)]
for i in range(m):
    a, b = map(int, readline().split())
    graph[a].append(b)
    graph[b].append(a)
ans = 0
for check in permutations(range(1, n + 1)):
    if check[0] != 1:
        break
    for u, v in zip(check, check[1:]):
        if v not in graph[u]:
            break
    else:
        ans += 1
print(ans)
