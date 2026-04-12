import copy

N,M = list(map(int,input().rstrip().split()))
sides = []
for i in range(M):
    ab = list(map(int,input().rstrip().split()))
    sides.append(ab)
    ba = [ab[1],ab[0]]
    sides.append(ba)

explored = [False for i in range(N+1)]
explored[0] = True
explored[1] = True

def explore(currentposition,flg):
    count = 0
    if all(flg):
        return 1
    for p in sides:
        if p[0] == currentposition and flg[p[1]]==False:
            tmp_flg = copy.deepcopy(flg)
            tmp_flg[p[1]] = True
            count += explore(p[1],tmp_flg)
    return count

print(explore(1,explored))