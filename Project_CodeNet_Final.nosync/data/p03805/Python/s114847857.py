from collections import defaultdict

N, M = map(int, raw_input().split())
X = [map(int, raw_input().split()) for _ in range(M)]

D = defaultdict(list)
for a, b in X:
    D[a].append(b)
    D[b].append(a)


def dfs(now, p):
    cnt = 0
    if set(now) == set(range(1, N+1)):
        return 1
    for k in D[p]:
        if k in now:
            continue
        cnt += dfs(now + [k], k)
    return cnt

print dfs([1], 1)
