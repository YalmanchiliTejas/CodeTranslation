import collections
import copy

n = int(input())
now = list(input())
ans = collections.Counter(now)
now = set(now)

for i in range(n-1):
    s = list(input())
    li = collections.Counter(s)
    now = set(s) & now
    d = ans.copy()
    ans = dict()
    for i in now:
        ans[i] = min(d[i], li[i])

if len(list(ans.keys())) == 0:
    print("")
    exit()
ansli = []
for i in ans:
    ansli += [i]*ans[i]

ansli.sort()
print("".join(map(str, ansli)))