from itertools import permutations

n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

ans = 0
lst = [i for i in range(n)]
lsts = list(permutations(lst, n))

for lst in lsts:
    if lst[0] != 0:
        continue
    now = 0
    for l in lst[1:]:
        if not l in graph[now]:
            break
        now = l
    else:
        ans += 1
print(ans)