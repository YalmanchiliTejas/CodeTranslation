input()
aa = list(map(int, input().split()))
state = {(0,False)}
skipmax = len(aa)%2 + 1
state_all = {(i, True) for i in range(skipmax+1)}.union({(j, False) for j in range(skipmax+1)})
dp_0 = {a:None for a in state_all }
dp_0[(0,False)] = 0
skipcount = 0

def getmax(a, b):
    if a is None:
        return b
    if b is None:
        return a
    return max(a,b)

for i,a in enumerate(aa):
    dp_1 = {}
    for s in state_all:
        if s[1] & (dp_0[(s[0], False)] is not None):
            dp_1[s] = dp_0[(s[0], False)] + a
            continue
        dp_1[s] = getmax(dp_0[(s[0], True)], dp_0.get((s[0]-1, False), None))
    dp_0 = dp_1.copy()
if len(aa)%2:
    print(getmax(dp_0[(2,True)], dp_0[(1,False)]))
else:
    print(getmax(dp_0[(1,True)], dp_0[(0,False)]))
