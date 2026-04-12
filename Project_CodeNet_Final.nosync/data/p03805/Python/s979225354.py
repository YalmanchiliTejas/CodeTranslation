n,m = list(map(int,input().split()))
from collections import defaultdict
 
dc = defaultdict(list)
for i in range(m):
    a,b = list(map(int,input().split()))
    dc[a].append(b)
    dc[b].append(a)

ans = 0
from itertools import permutations
comb = list(permutations(range(2,n+1),n-1))
for c in comb:
    flag = True
    targets = list(c)
    # print(c)
    if not 1 in dc[targets[0]]:
        flag = False
    for i in range(len(targets)-1):
        a,b = targets[i],targets[i+1]
        if not b in dc[a]:
            flag = False
            break
    if flag:
        # print(c," is ok")
        ans += 1

print(ans)