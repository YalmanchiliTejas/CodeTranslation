from sys import stdin
def input():
    return stdin.readline().strip()

n, m = map(int, input().split())
tree = [[] for _ in range(n)]
for _ in range(m):
    i, j = map(int, input().split())
    i -= 1
    j -= 1
    tree[i].append(j)
    tree[j].append(i)

# BFS
from collections import deque

# todoに(現在の頂点, [通った頂点の履歴])を追加する
first = [True] * n
first[0] = False
todo = deque([(0, first)])
ans = 0
while len(todo) > 0:
    now, history = todo.popleft()
    if not any(history):
        ans += 1
        continue
    for i in tree[now]:
        if history[i]:
            next_history = history.copy()
            next_history[i] = False
            todo.append((i, next_history))

print(ans)