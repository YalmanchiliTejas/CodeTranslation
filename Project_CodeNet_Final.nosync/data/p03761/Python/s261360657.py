from collections import Counter

n,*S = open(0).read().split()
c = Counter(S[0])
for s in S[1:]:
    temp = Counter(s)
    remove = set()
    for x in c.items():
        if temp[x[0]] > 0:
            c[x[0]] = min(c[x[0]],temp[x[0]])
        else:
            remove.add(x[0])
    for x in remove:
        del c[x]
if len(c) == 0:
    print('\n')
else:
    s = sorted([x for x in c.items()])
    ans = []
    for x in s:
        ans.append(x[0]*x[1])
    print(''.join(ans))