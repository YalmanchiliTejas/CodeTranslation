n,m = map(int,input().split())
edge = []
for i in range(n+1):
    edge.append([])
for i in range(m):
    a,b = map(int,input().split())
    edge[a].append(b)
    edge[b].append(a)
ans = 0

import itertools
def permutation_all(seq, choice):
    return list(itertools.permutations(seq, choice))

cond = [i for i in range(2,n+1)]
cond = permutation_all(cond, n-1)
for i in range(len(cond)):
    here = 1
    tar = cond[i]
    flag = True
    for j in range(n-1):
        if tar[j] not in edge[here]:
            flag= False
            break
        else:
            here = tar[j]
    if flag:
        ans += 1
print(ans)
