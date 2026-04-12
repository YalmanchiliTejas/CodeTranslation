import itertools


def f(j, adj):
    for i, node in enumerate(j):
        if i == 0:
            if node not in adj[1]:
                return False
        else:
            if j[i - 1] not in adj[node]:
                return False
    return True


n, m = map(int, input().split())

adj = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

count = 0
for j in itertools.permutations(range(2, n + 1)):
    count += f(j, adj)

print(count)
