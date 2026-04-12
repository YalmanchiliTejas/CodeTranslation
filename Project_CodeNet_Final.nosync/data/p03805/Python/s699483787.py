import itertools

N, M = map(int, input().split())
G = [[]  for _ in range(N)]
for i in range(M):
    a, b = map(lambda x: int(x) - 1, input().split())
    G[a].append(b)
    G[b].append(a)
pattern = [i for i in range(N)]

ans = 0
for i in itertools.permutations(pattern):
    flag = True
    if i[0] != 0:
        continue
    for j in range(len(i) - 1):
        now = i[j]
        next = i[j+1]
        if not next in G[now]:
            flag = False
    if flag:
        ans += 1
print(ans)