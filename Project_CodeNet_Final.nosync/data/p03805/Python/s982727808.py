import itertools
N, M = map(int, input().split())
edge = [[] for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)


def isOK(seq):
    s = 1
    for t in seq:
        if t in edge[s]:
            s = t
        else:
            return False
    return True


ans = 0
for seq in itertools.permutations(range(2, N + 1)):
    if isOK(seq):
        ans += 1

print(ans)
