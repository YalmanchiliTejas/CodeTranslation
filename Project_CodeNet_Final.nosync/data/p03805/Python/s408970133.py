from itertools import permutations as per
n,m = map(int,input().split())
g = [[] for _ in range(n+1)]
for i in range(m):
    a,b = map(int,input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)
ans = 0

for l in per(range(n)):
    if l[0] != 0:
        continue
    flag = 1
    for i in range(n-1):
        if l[i+1] not in g[l[i]]:
            flag = 0
            break
    if flag:
        ans += 1
print(ans)