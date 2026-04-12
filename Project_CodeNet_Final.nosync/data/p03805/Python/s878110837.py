import itertools

n, m = map(int, input().split())
edges = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(lambda x: int(x) - 1, input().split())
    edges[a].append(b)
    edges[b].append(a)

count = 0
for perm in itertools.permutations(range(1, n)):
    if not perm[0] in edges[0]:
        continue
    can_visit_all = True
    for i in range(n - 2):
        if not perm[i + 1] in edges[perm[i]]:
            can_visit_all = False
            break
    if can_visit_all:
        count += 1
print(count)
