import itertools
import copy
n, m = map(int, input().split())
graph = [[] * n for i in range(n)]
for _ in range(m):
    num_from, num_to = map(int, input().split())
    graph[num_from - 1].append(num_to - 1)
    graph[num_to - 1].append(num_from - 1)

count = 0
node_list = [i + 1 for i in range(n - 1)]
for pattern in itertools.permutations(node_list):
    pattern_list = list(pattern)
    pattern_list.insert(0, 0)
    can_arrive = False
    for i in range(n):
        if i == n - 1:
            can_arrive = True
            break
        if pattern_list[i + 1] not in graph[pattern_list[i]]:
            can_arrive = False
            break
    if can_arrive:
        count += 1

print(count)