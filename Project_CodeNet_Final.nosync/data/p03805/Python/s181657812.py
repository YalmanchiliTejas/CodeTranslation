import itertools

N, M = map(int, input().split(" "))
path = [[False for j in range(N)] for i in range(N)]

for i in range(M):
    a, b = map(int, input().split(" "))
    path[a-1][b-1] = True
    path[b-1][a-1] = True

count = 0
for order in itertools.permutations(range(1, N)):
    before = 0
    for nextNode in order:
        if not path[before][nextNode]:
            break
        before = nextNode
    if before == order[-1]:
        count += 1
print(count)
