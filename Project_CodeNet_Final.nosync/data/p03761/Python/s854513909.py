from collections import Counter

n = int(input())
ans = Counter(input())

for i in range(n - 1):
    _ans = ans.copy()
    c = Counter(input())
    s = _ans.keys() & c.keys()
    ans = {}
    for k in s:
        ans[k] = min(_ans[k], c[k])

anstr = "".join(sorted([k * ans[k] for k in ans.keys()]))

print(anstr)
