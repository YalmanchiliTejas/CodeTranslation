import itertools

N, M = map(int, input().split())

d = dict()
for i in range(1, N+1):
    d[i] = list()
for m in range(M):
    a, b = map(int, input().split())
    d[a].append(b)
    d[b].append(a)

ans = 0
for p in itertools.permutations(range(2, N+1)):
    nodes = {1}
    prev_node = 1
    for i, n in enumerate(p):
        if n not in d[prev_node]:
            break

        else:
            prev_node = n
            nodes.add(n)

        if len(nodes) == N:
            ans += 1
            break

print(ans)