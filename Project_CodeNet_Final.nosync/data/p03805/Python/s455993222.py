from collections import deque

N, M = map(int, raw_input().split())
nodes = {i:[] for i in range(1, N+1)}
for _ in range(M):
  a, b = map(int, raw_input().split())
  nodes[a] += [b]
  nodes[b] += [a]
stack = deque([[1, []]])
ans = 0
while stack:
  n, history = stack.pop()
  if len(history) == N - 1:
    ans += 1
    continue
  node = nodes[n]
  for next_node in node:
    if not next_node in history:
      stack.append([next_node, history+[n]])
print ans

