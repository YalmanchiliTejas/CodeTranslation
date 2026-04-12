import itertools

N, M = map(int, input().split())

E = [set() for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    E[a].add(b)
    E[b].add(a)

ret = 0
for path in itertools.permutations(range(2, N + 1)):
    if path[0] not in E[1]:
        continue
    f = True

    for i in range(N - 2):
        if path[i + 1] not in E[path[i]]:
            f = False
            break
    if f:
        ret += 1

print(ret)
