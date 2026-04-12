n = input()
g = [[] for i in xrange(n)]
for i in xrange(n-1):
    a, b = map(int, raw_input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)
import sys
sys.setrecursionlimit(10**6)
used = {}
flag = [[0]*2 for i in xrange(n)]
def dfs(v, prev):
    if (v, prev) in used:
        return used[v, prev]
    su = 1
    for t in g[v]:
        if t != prev:
            su += dfs(t, v)
    used[v, prev] = su
    return su

for i in xrange(n):
    dfs(i, -1)
for v in xrange(n):
    cnt_o = 0
    for t in g[v]:
        if used[t, v] % 2 == 1:
            cnt_o += 1
    if cnt_o > 1:
        print "First"
        break
else:
    print "Second"
