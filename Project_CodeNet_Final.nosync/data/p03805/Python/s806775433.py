import itertools

n,m=map(int,input().split())
l=[i for i in range(1,n)]
g=[[] for _ in range(n)]
for _ in range(m):
    a,b=map(int,input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)

res = 0
for sp in itertools.permutations(l):
    flag = 1
    s = 0
    for i in range(n-1):
        if not (sp[i] in g[s]):
            flag = 0
            break
        else:
            s = sp[i]
    if flag == 1:
        res += 1

print(res)