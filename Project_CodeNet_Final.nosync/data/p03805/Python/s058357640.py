from itertools import permutations

N, M = map(int, input().split())
graph = []
for i in range(M):
    a, b = map(int, input().split())
    graph.append(set((a, b)))

g = permutations(range(1, N + 1))

count = 0
for order in g:
    flag = True
    for i in range(N-1):
        if set((order[i], order[i + 1])) not in graph or order[0] != 1:
            flag = False
            break
    if flag:
        count += 1

print(count)