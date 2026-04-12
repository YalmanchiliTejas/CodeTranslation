import sys
import itertools

n, m = map(int, input().split())

nextList = [set() for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    nextList[a].add(b)
    nextList[b].add(a)

count = 0

nodes = range(2, n+1)
for v in itertools.permutations(nodes, n-1):
    now = 1
    error = False
    for i in v:
        if not i in nextList[now]:
            error = True
            break
        now = i
    if error != True:
        count += 1

print(count)

