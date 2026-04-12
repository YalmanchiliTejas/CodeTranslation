import itertools

n, m = map(int, input().split())
graph = {i + 1 : set() for i in range(n)}
for i in range(m):
    a, b = map(int, input().split())
    graph[a] |= set([b])
    graph[b] |= set([a])
count = 0
node = [i + 2 for i in range(n - 1)]
for i in itertools.permutations(node):
    route = [1] + list(i)
    flag = True
    for j in range(n - 1):
        if route[j + 1] not in graph[route[j]]:
            flag = False
            break
    if flag == True:
        count += 1
print(count)