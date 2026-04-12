from itertools import permutations

N, M = map(int, input().split())
E = {i: set() for i in range(1, 1 + N)}
for _ in range(M):
    a, b = map(int, input().split())
    E[a].add(b)
    E[b].add(a)
ans = 0
for perm in permutations([i for i in range(2, 1 + N)]):
    perm = [1] + list(perm)
    ok = True
    for i in range(len(perm) - 1):
        prv = perm[i]
        nxt = perm[i + 1]
        if nxt not in E[prv]:
            ok = False
    if ok:
        ans += 1
print(ans)
