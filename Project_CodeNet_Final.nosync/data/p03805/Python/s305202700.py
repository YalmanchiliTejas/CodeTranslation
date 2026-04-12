import itertools
N, M, *AB = [int(_) for _ in open(0).read().split()]
G = [set() for _ in range(N)]
for a, b in zip(AB[::2], AB[1::2]):
    a -= 1
    b -= 1
    G[a].add(b)
    G[b].add(a)
ans = 0
for root in itertools.permutations(range(1, N), N - 1):
    root = [0] + list(root)
    if all(a in G[b] for a, b in zip(root, root[1:])):
        ans += 1
print(ans)
