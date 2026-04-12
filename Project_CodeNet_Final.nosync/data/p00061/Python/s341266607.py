from bisect import bisect
import sys

d = {}
p = []
for s in sys.stdin:
    t,n = map(int,s.split(","))
    if [t,n] == [0,0]: break
    d[t] = n
    p.append(n)

p = sorted(list(set(p)))
for s in sys.stdin:
    print len(p)+1 -bisect(p, d[int(s)])