from collections import defaultdict
import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.buffer.readline
N,M = map(int,input().split())
g = defaultdict(list)

for i in [0]*M:
    a,b = (map(int,input().split()))
    g[a].append(b)
    g[b].append(a)

f = [False]*N

ans = 0
def rec(s,f_):
    global ans
    f_[s-1] = True
    if sum(f_) == N:
        ans += 1
        return
    for t in g[s]:
        if not f_[t-1]:
            rec(t,f_[:])
    return 
rec(1,f[:])
print(ans)





