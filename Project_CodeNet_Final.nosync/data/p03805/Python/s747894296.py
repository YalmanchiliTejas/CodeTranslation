import itertools

n, m = map(int, input().split())

edges = []
for i in range(m):
    edges.append(tuple(map(int, input().split())))

reverse_edges = [e[::-1] for e in edges]
# print(edges)
# print(reverse_edges)
# print(edges + reverse_edges)
edges += reverse_edges

count = 0
start = 1
end = 1
for series in itertools.permutations(range(2, n + 1)):
    # print('candidate', series)
    start, end = 1, 1
    conflict = False
    for i in series:
        edge = (start, i)
        # print(edge)
        if edge not in edges:
            conflict = True
            # print('conflict', edge)
            break
        start = i
    if not conflict:
        count +=1

print(count)

