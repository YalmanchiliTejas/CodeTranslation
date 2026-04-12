import itertools

n, m = [int(_) for _ in input().split(' ')]
edges = set()
for _ in range(m):
    a, b = [int(_) for _ in input().split(' ')]
    edges.add((a, b))
    edges.add((b, a))

answer = 0
for vertices in itertools.permutations(range(2, n + 1)):
    steps = [1] + list(vertices)
    if all([(steps[i], steps[i + 1]) in edges for i in range(n - 1)]):
        answer += 1
print(answer)
