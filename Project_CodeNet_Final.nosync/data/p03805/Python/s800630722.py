import itertools as it

N, M = map(int, input().split())
ab = tuple(set(map(int, input().split())) for _ in range(M))

P = it.permutations(range(1, N + 1), N)

res = 0
for p in P:
    if p[0] == 1:
        for i in range(N - 1):
            if not(set({p[i], p[i + 1]}) in ab):
                break
        else:
            res += 1

print(res)