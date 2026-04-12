import copy

N, M = list(map(int, input().split()))
route = [[0 for i in range(N)] for l in range(N)]
count = 0
for i in range(M):
    a, b = list(map(int, input().split()))
    route[a-1][b-1] = 1
    route[b-1][a-1] = 1

queue = [[[0],i] for  i in range(N) if route[0][i]]

while len(queue):
    r = queue.pop(0)
    n = r[1]
    r[0].append(n)
    if len(r[0]) == N:
        count += 1
    else:
        for i in range(1, N):
            if route[n][i] and i not in r[0]:
                x = copy.deepcopy(r[0])
                queue.append([x, i])

print(count)
