import itertools

n, m = map(int, input().split())
edge = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    edge[a - 1].append(b - 1)
    edge[b - 1].append(a - 1)

lst = [i + 1 for i in range(n - 1)]
ans = 0
for step in itertools.permutations(lst):
    flag = True
    now = 0
    for i in range(n - 1):
        if step[i] in edge[now]:
            now = step[i]
        else:
            flag = False
            break
    if flag:
        ans += 1

print(ans)