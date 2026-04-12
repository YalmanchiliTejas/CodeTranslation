from itertools import *
n,m = map(int,input().split())
path = [set() for _ in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    path[a-1].add(b-1)
    path[b-1].add(a-1)
ans = 0

for r in permutations(list(range(1,n))):
    p = 0
    flag = True
    for i in r:
        if not i in path[p]:
            flag = False
        p = i
    if flag:
        ans += 1
print(ans)
