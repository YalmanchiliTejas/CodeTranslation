n = int(input())
import collections

a = list(input())
ans = collections.Counter(a)
for i in range(n-1):
    l = collections.Counter(list(input()))
    for i in ans.keys():
        if i in l:
            ans[i] = min(ans[i],l[i])
        else:
            ans[i] = 0
l = []
for i in ans.keys():
    for j in range(ans[i]):
        l.append(i)
if len(l) == 0:
    print("")
else:
    l.sort()
    print(*l,sep="")