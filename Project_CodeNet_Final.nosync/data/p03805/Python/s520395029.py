import sys
import copy
from collections import deque

count = 0
n, m = (int(x) for x in sys.stdin.readline().split())
a_b_list = [[int(x) for x in sys.stdin.readline().split()] for y in range(m)]
# 始点が1のパスをキューに入れる
q = deque([])
for i in a_b_list:
    if i[0] != 1 and i[1] != 1:
        continue
    if i[0] == 1:
        q.append([1, i[1]])
    if i[1] == 1:
        q.append([1, i[0]])
#  幅優先探索(?)
while len(q) > 0:
    path = q.popleft()
    if len(path) == n:
        count += 1
        continue
    q_q = deque([i for i in range(2, n + 1) if i not in path])
    while len(q_q) > 0:
        destination = q_q.popleft()
        if [path[-1], destination] in a_b_list or [destination, path[-1]] in a_b_list:
            new_path = copy.copy(path)
            new_path.append(destination)
            q.append(new_path)
print(count)
