import sys
d={}
f=0
for s in sys.stdin:
    if f==0:
        a,b=map(int,s.split(","))
        if a!=0 or b!=0:d[a]=b
        else:
            x=sorted(set(d.values()))[::-1]
            f=1
    else:print x.index(d[int(s)])+1