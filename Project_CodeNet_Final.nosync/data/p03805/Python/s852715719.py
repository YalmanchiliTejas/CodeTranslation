from collections import deque

N, M = map(int, raw_input().split())
way = {}
for _ in xrange(M):
    a, b = map(int, raw_input().split())
    if a not in way:
        way[a] = set()
    if b not in way:
        way[b] = set()
    way[a].add(b)
    way[b].add(a)

counter = 0
states = deque([({1}, 1)])
while states:
    passed, current = states.popleft()
    if len(passed) == N:
        counter += 1
        continue
    for next_index in way.get(current, []):
        if next_index not in passed:
            states.append((passed | {next_index}, next_index))
print counter