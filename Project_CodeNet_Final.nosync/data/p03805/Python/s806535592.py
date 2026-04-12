from itertools import permutations

N, M = map(int, input().split())
edges = set()
for _ in range(M):
    a, b = map(int, input().split())
    edges.add((a, b))
    edges.add((b, a))

cnt = 0
for p in permutations(range(2, N + 1)):
    cnt += all(move in edges for move in zip((1,) + p, p))
print(cnt)