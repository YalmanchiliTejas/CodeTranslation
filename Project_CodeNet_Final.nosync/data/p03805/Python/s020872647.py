from itertools import permutations

n, m = map(int, input().split())
graph = [set(map(lambda n: int(n) - 1, input().split())) for _ in range(m)]

print(sum(all(({0, per[i]} if not i else {per[i - 1], per[i]}) in graph for i in range(n - 1)) for per in permutations(i for i in range(1, n))))
