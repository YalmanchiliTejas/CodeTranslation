import sys
d,e={},{}
for x in iter(input,'0,0'):
 p,s=map(int,x.split(','))
 d.setdefault(s,[]);d[s]+=[p]
 e[p]=s
for y in sys.stdin:print(sorted(d.keys())[::-1].index(e[int(y)])+1)
