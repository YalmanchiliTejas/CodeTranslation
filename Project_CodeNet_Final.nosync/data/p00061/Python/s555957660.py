import sys
d={}
f=0
for s in sys.stdin:
    if f==0:
        a,b=map(int,s.split(","))
        if a==0 and b==0:
            x=sorted(set(d.values()))[::-1]
            f=1
        else:d[a]=b
    else:
        print x.index(d[int(s)])+1