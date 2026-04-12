from itertools import permutations

n, m = map(int, input().split())
g = {i: [] for i in range(1, n+1)}

for _ in range(m):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

p = permutations([x for x in range(2, n+1)])

res = 0
for l in p:
    tmp = g[1]
    for x in l:
        if x in tmp:
            tmp = g[x]
        else:
            break
    else:
        res += 1

print(res)