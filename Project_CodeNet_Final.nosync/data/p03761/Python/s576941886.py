from collections import Counter

def cntmin(c1, c2):
    c = Counter()
    for k in c1:
        c[k] = min(c1[k], c2[k])
    return c

n = int(raw_input())
S = [raw_input() for _ in range(n)]

ans = None
for s in S:
    c = Counter(s)
    if ans != None:
        ans = cntmin(ans, c)
    else:
        ans = c

print "".join(sorted(ans.elements()))
