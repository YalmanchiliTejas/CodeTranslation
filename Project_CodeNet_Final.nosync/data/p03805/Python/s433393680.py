import collections
import itertools

N, M = map(int, input().split())
a, b = list(zip(*[map(int, input().split()) for _ in range(M)]))

paths = collections.defaultdict(list)
for i in range(M):
    paths[a[i] - 1].append(b[i] - 1)
    paths[b[i] - 1].append(a[i] - 1)

ans = 0
for perm in itertools.permutations(range(N)):
    if perm[0] != 0:
        continue

    for i in range(1, N):
        if perm[i] not in paths[perm[i - 1]]:
            break
    else:
        ans += 1

print(ans)
