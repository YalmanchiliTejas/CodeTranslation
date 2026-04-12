import itertools

N, M = map(int, input().split())
ab = [[int(i) for i in input().split()] for j in range(M)]

G = [[] for i in range(N)]
for i in range(M):
    a, b = ab[i]
    G[a-1].append(b-1)
    G[b-1].append(a-1)

ls = [i for i in range(1, N)]
ans = 0
for route in itertools.permutations(ls, N-1):
    pre = 0
    for i in range(N-1):
        next_v = route[i]
        if next_v not in G[pre]:
            break
        pre = next_v
    else: ans += 1

print(ans)