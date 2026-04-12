import itertools

n, m = map(int, input().split())
path = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    path[a].append(b)
    path[b].append(a)

ans = 0
for i in itertools.permutations(range(n), n):
    if i[0] == 0:
        flag = True
        for j in range(n-1):
            if not i[j+1] in path[i[j]]:
                flag = False
        if flag:
            ans += 1
print(ans)