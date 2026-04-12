import bisect
from collections import deque
n=int(input())
a=[int(input()) for _ in range(n)]

q=[]
def bisect_desc(a,x):
    r = len(a)
    if r == 0:
        return 0
    l = 0
    while l != r:
        f = (l+r)//2
        if a[f] >= x:
            l = f+1
        else:
            r = f
    return l

for sa in a:
    t = bisect_desc(q,sa)
    if t ==len(q):
        q.append(sa)
    else:
        q[t] = sa

print(len(q))