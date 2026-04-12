from collections import defaultdict

N, M = map(int, input().split())

edges = defaultdict(set)
used = [False] * N
for i in range(M):
    a, b = map(int, input().split())
    edges[a-1].add(b-1)
    edges[b-1].add(a-1)

def count(index):
    if all(used):
        return 1

    total = 0
    for dest in edges[index]:
        if not used[dest]:
            used[dest] = True
            total += count(dest)
            used[dest] = False
    return total

used[0] = True
print(count(0))