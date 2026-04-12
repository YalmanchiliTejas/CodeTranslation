import itertools
n, m = map(int, input().split())
l = [list(map(int, input().split())) for i in range(m)]
r = [[] for i in range(n + 1)]
ans = 0
for i in range(m):
    r[l[i][0]].append(l[i][1])
    r[l[i][1]].append(l[i][0])
p = []
for i in range(n):
    p.append(i + 1)
p = list(itertools.permutations(p))
for i in range(len(p)):
    check = True
    t = list(p[i])
    if t[0] != 1:
        check = False
    for j in range(len(t)-1):
        if not t[j + 1] in r[t[j]]:
            check = False
    if check:
        ans += 1
print(ans)