from networkx import *
n, m = map(int, input().split())
a = [list(map(int, input().split())) for i in range(m)]
g = Graph(a)
ans = 0
for i in range(2, n + 1):
  for p in all_simple_paths(g, 1, i):
    if len(p) == n:
      ans += 1
print(ans)