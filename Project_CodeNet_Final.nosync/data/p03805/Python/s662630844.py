import itertools

n,m = map(int,input().split())
path = [[] for i in range(n+1)]
for i in range(m):
    a,b = map(int,input().split())
    path[a].append(b)
    path[b].append(a)

ans = 0
l = [i for i in range(2,n+1)]
for v in itertools.permutations(l,n-1):
    flag = True
    if v[0] not in path[1]:
        flag = False
        continue
    for k in range(1,n-1):
        if v[k] not in path[v[k-1]]:
            flag = False
            continue
    if flag:
        ans += 1

print(ans)
