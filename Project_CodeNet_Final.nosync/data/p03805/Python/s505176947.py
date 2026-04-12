from itertools import permutations

n, m = map(int, input().split())
edges = set()
for _ in range(m):
    a, b = map(int, input().split())
    edges.add((a, b))
    edges.add((b, a))

print(sum(all(move in edges for move in zip((1,)+p, p)) for p in permutations(range(2, n+1))))