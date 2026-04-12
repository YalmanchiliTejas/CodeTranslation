N, M = map(int, input().split())

g = {}
n_path = 0
for i in range(N):
    g[i] = []
for _ in range(M):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    g[a].append(b)
    g[b].append(a)


def advance(v, passed):

    global n_path
    passed.append(v)
    if len(passed) == N:
        n_path += 1

    for n in g[v]:
        if n not in passed:
            advance(n, passed)

    passed.remove(v)


advance(0, [])
print(n_path)
