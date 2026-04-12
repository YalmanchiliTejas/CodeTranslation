
N , M = map(int, input().split())

def mkmap(N, M):
    mapdic = {}
    for i in range(1, N+1):
        mapdic[str(i)] = [] 
    for j in range(M):
        pathA, pathB = map(str, input().split())
        mapdic[pathA] = mapdic[pathA] + [pathB]
        mapdic[pathB] = mapdic[pathB] + [pathA]
    return mapdic

mapdic = mkmap(N, M)
import copy

roots = [[]]*N
roots[0] = ["1"]
for i in range(N-1):
    root = copy.deepcopy(roots[i])
    for nowroot in root:
        for nextroot in mapdic[nowroot[-1]]:
            if  i >= 1:
                if not nextroot in nowroot:                    
                    roots[i+1] = roots[i+1] + [nowroot + nextroot]
                else:
                    pass
            else:
                roots[i+1] = roots[i+1] + [nowroot + nextroot]


List = [str(n+1) for n in range(N)]
check = "".join(List)
ans = 0
for i in roots[-1]:
    TF = "".join(sorted(list(i))) == check
    if TF:
        ans = ans + 1

print(ans)