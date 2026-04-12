from itertools import permutations

N, M = map(int, input().split())
g = [[0] * N for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1

    g[a][b] = 1
    g[b][a] = 1
# print(g)
check = set()

path = list(permutations(range(N)))

for t in path:
    if t[0] != 0:
        continue
    flag = True
    for i in range(N - 1):
        if g[t[i]][t[i + 1]] != 1:
            flag = False
            break
    if flag:
        check.add(t)

# print(check)
print(len(check))
